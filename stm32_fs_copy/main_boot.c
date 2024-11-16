
#include <stdint.h>
#include "stm32f767xx.h"
#include "system_stm32f7xx.h"

#define LED_PIN 7

// linker variables must be accessed by their address (not value), using an array reference accomplished this too.
// https://stackoverflow.com/a/54728097/13745806
extern uint32_t __flash_app_start__[];

void blink()
{
    GPIOB->ODR ^= (1 << LED_PIN);
}

void GPIOB_init()
{
    // GPIO port B RCC enable
    RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOBEN_Pos);
    // set pin 0 as mode general purpose output
    GPIOB->MODER |= (1 << GPIO_MODER_MODER7_Pos);
}

static void start_app(uint32_t pc, uint32_t sp)
{
    __asm("           \n\
          msr msp, r1 /* load R1 (second argument) into MSP */\n\
          bx r0       /* branch to address in R0 (first argument)*/\n\
    ");
}

extern uint32_t isr_vector[];
int main(void)
{
    GPIOB_init();
    for (uint32_t i = 0; i < 8; i++)
    {
        for (uint32_t i = 0; i < 500000; i++)
            ;
        blink();
    }

    uint32_t *app_code = (uint32_t *)__flash_app_start__;
    uint32_t app_sp = app_code[0];
    uint32_t app_start = app_code[1];
    start_app(app_start, app_sp);

    while (1)
    {
        for (uint32_t i = 0; i < 500000; i++)
            ;
        blink();
    }
}