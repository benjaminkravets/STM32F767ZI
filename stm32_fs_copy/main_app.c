
#include <stdint.h>

// stdio.h has line extern int printf (const char *__restrict __format, ...);
#include <stdio.h>
#include "stm32f767xx.h"
#include "system_stm32f7xx.h"
#include "usart.h"
#include "dma.h"
#include "spi.h"

#define LED_PIN 0 // 0 - green, 7 - blue, 14 - red

uint32_t ticks;
void systick_handler()
{
    ticks++;
}

void delay_ms(uint32_t milliseconds)
{
    uint32_t start = ticks;
    uint32_t end = start + milliseconds;
    // if end time is less than start, wait until this is not the case (ticks will wrap around to 0)
    if (end < start)
    {
        while (ticks > start)
            ;
    }
    // wait until end time is reached
    while (ticks < end)
        ;
}

void blink()
{
    GPIOB->ODR ^= (1 << LED_PIN);
}

void clock_init()
{
    // bypass oscillator with an external clock and enable the high speed external clock
    RCC->CR |= RCC_CR_HSEBYP_Msk | RCC_CR_HSEON_Msk;
    // wait until HSE clock is ready
    while (!(RCC->CR & RCC_CR_HSERDY_Msk))
        ;
    // power interface clock enable to use power controller
    RCC->APB1ENR |= RCC_APB1ENR_PWREN_Msk;

    // scale 1 mode (higher performance and power consumption)
    PWR->CR1 |= (0b11 << PWR_CR1_VOS_Pos);

    // set # of wait states (clock cycles required between CPU flash read dispatch (CPU provides read address) and a stable flash memory controller output.)
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;

    // reset then set m, n, and p to 4, 200, and 4 where HSE -> /M -> *N -> /P
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM_Msk |
                      RCC_PLLCFGR_PLLN_Msk |
                      RCC_PLLCFGR_PLLP_Msk);

    RCC->PLLCFGR |= ((4 << RCC_PLLCFGR_PLLM_Pos) |
                     (200 << RCC_PLLCFGR_PLLN_Pos) |
                     (1 << RCC_PLLCFGR_PLLP_Pos) |
                     (1 << RCC_PLLCFGR_PLLSRC_Pos));

    // APB1 clock prescalar = 4, APB2 clock prescalar = 4
    RCC->CFGR |= (0b101 << RCC_CFGR_PPRE1_Pos);
    RCC->CFGR |= (0b110 << RCC_CFGR_PPRE2_Pos); // SPI

    // PLL on
    RCC->CR |= RCC_CR_PLLON_Msk;

    // wait until main PLL is ready
    while (!(RCC->CR & RCC_CR_PLLRDY_Msk))
        ;
    // out of HSI, HSE, and PLL, use PLL
    RCC->CFGR |= (RCC_CFGR_SW_PLL << RCC_CFGR_SW_Pos);

    // wait while PLL is not selected as the system clock
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL))
        ;
}

void GPIOB_init()
{
    // GPIO port B RCC enable
    RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOBEN_Pos);
    // set pin 0 as mode general purpose output
    GPIOB->MODER |= (1 << GPIO_MODER_MODER0_Pos);
}

void using_spi()
{
    while (1)
    {
        uint8_t here[] = "abcdefedc";
        SPI_write(SPI4, here, 0, 0);
        delay_ms(500);
    }
}

void SYSCFG_init() {
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN_Msk;
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI12_PC;
    EXTI->RTSR |= EXTI_RTSR_TR13_Msk;
    EXTI->FTSR |= EXTI_FTSR_TR13_Msk;
}

int main()
{
    clock_init();
    // change CMSIS internal clock variable
    SystemCoreClockUpdate();

    // set ticks between interrupts as 100000
    SysTick_Config(100000);
    // enable interrupts
    __enable_irq();

    GPIOB_init();
    USART3_init();
    SPI_init();
    DMA2_channel_init();

    using_dma();
    using_spi();

    // while (1)
    // {
    //     char z = '0';
    //     // char z = getchar();
    //     delay_ms(500);
    //     printf("Hello \r\n");
    //     blink();
    // }
}
