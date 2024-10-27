
#include <stdint.h>

#include "stm32f767xx.h"
#include "system_stm32f7xx.h"

#define LED_PIN 0

uint32_t ticks;
void systick_handler()
{
    ticks++;
}
void delay_ms(uint32_t milliseconds)
{
    uint32_t start = ticks;
    uint32_t end = start + milliseconds;
    if (end < start)
    {
        while (ticks > start)
            ;
    }
    while (ticks < end)
        ;
}
void blinker()
{
    while (1)
    {
        GPIOB->ODR ^= (1 << LED_PIN);
        for (uint32_t i = 0; i < 1000000; i++)
        {
        };
    }
}

int main()
{
    //bit 18 bypasses oscillator with an external clock and the high speed external clock is enabled
    RCC->CR |= RCC_CR_HSEBYP_Msk | RCC_CR_HSEON_Msk;
    //wait until HSE clock is ready
    while (!(RCC->CR & RCC_CR_HSERDY_Msk))
        ;
    //enable power interface clock
    RCC->APB1ENR |= RCC_APB1ENR_PWREN_Msk;

    //scale 1 mode (higher performance and power consumption)
    PWR->CR1 != (0b11 << PWR_CR1_VOS_Pos);

    //set # of wait states (clock cycles required between CPU flash read dispatch (CPU provides read address) and a stable flash memory controller output.)
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;

    // reset then set m, n, and p to 4, 200, and 4 where HSE -> /M -> *N -> /P
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM_Msk |
                      RCC_PLLCFGR_PLLN_Msk |
                      RCC_PLLCFGR_PLLP_Msk);

    RCC->PLLCFGR |= ((4 << RCC_PLLCFGR_PLLM_Pos) |
                     (200 << RCC_PLLCFGR_PLLN_Pos) |
                     (1 << RCC_PLLCFGR_PLLP_Pos) |
                     (1 << RCC_PLLCFGR_PLLSRC_Pos));

    RCC->CFGR |= (0b100 << RCC_CFGR_PPRE1_Pos);

    RCC->CR |= RCC_CR_PLLON_Msk;
    while (!(RCC->CR & RCC_CR_PLLRDY_Msk))
        ;

    RCC->CFGR |= (RCC_CFGR_SW_PLL << RCC_CFGR_SW_Pos);
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL))
        ;
    // clock_init();
    SystemCoreClockUpdate();

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN_Msk;
    volatile uint32_t dummy;
    GPIOB->MODER |= (1 << GPIO_MODER_MODER0_Pos);

    // SystemCoreClockUpdate();

    SysTick_Config(100000);
    __enable_irq();
    // blinker();

    while (1)
    {
        GPIOB->ODR ^= (1 << LED_PIN);
        delay_ms(500);
    }
}