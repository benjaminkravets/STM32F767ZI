
#include <stdint.h>


#include "stm32f767xx.h"
#include "system_stm32f7xx.h"

#define LED_PIN 7


uint32_t __flash_app_start__ = 0x08008000;



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
          msr msp, r1 /* load r1 into MSP */\n\
          bx r0       /* branch to the address at r0 */\n\
    ");
}

extern uint32_t isr_vector[];
int main(void)
{
    GPIOB_init();
    for (uint32_t i = 0; i < 5; i++)
    {

        for (uint32_t i = 0; i < 1000000; i++)
            ;
        blink();
    }

    uint32_t *app_code = (uint32_t *)__flash_app_start__;
    uint32_t app_sp = app_code[0];
    uint32_t app_start = app_code[1];
    start_app(app_start, app_sp);

    while (1)
    {
        for (uint32_t i = 0; i < 1000000; i++)
            ;
        blink();
    }
}