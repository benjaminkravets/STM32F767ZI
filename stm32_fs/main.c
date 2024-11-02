
#include <stdint.h>

// stdio.h has line extern int printf (const char *__restrict __format, ...);

#include <stdio.h>

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

void blinker()
{
    while (1)
    {
        GPIOB->ODR ^= (1 << LED_PIN);
        delay_ms(500);
    }
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
    PWR->CR1 != (0b11 << PWR_CR1_VOS_Pos);

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

    // APB clock divide by 2
    RCC->CFGR |= (0b100 << RCC_CFGR_PPRE1_Pos);

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
    // change CMSIS internal clock variable
    SystemCoreClockUpdate();
}

void GPIOB_init()
{
    // GPIO port B clock enable
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN_Msk;
    // set pin 0 as mode general purpose output
    GPIOB->MODER |= (1 << GPIO_MODER_MODER0_Pos);
}

void USART_init()
{
    RCC->APB1ENR |= (1 << RCC_APB1ENR_USART3EN_Pos);
    RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIODEN);

    GPIOD->MODER &= ~(GPIO_MODER_MODER8_Msk | GPIO_MODER_MODER9_Msk);
    GPIOD->MODER |= (0b10 << GPIO_MODER_MODER8_Pos | 0b10 << GPIO_MODER_MODER9_Pos);

    GPIOD->AFR[1] &= ~(GPIO_AFRH_AFRH0 | GPIO_AFRH_AFRH1);
    GPIOD->AFR[1] |= (7 << GPIO_AFRH_AFRH0_Pos) | (7 << GPIO_AFRH_AFRH1_Pos);

    USART3->BRR = 434;
    USART3->CR1 |= USART_CR1_UE | USART_CR1_TE;
}

void usart_write(USART_TypeDef *usart, char c)
{
    usart->TDR = c;
    while(!(usart->ISR & USART_ISR_TC_Pos));
}
int main()
{
    clock_init();

    GPIOB_init();
    USART_init();
    // while(1){
    //     printf("12");
    //     delay_ms(100);
    // }

    // set ticks between interrupts as 100000
    SysTick_Config(100000);
    // enable interrupts
    __enable_irq();

    blinker();
}
