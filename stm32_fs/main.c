
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

void USART3_init()
{
    // checklist in 34.5.2

    // enable USART 3 at RCC
    RCC->APB1ENR |= (1 << RCC_APB1ENR_USART3EN_Pos);
    // GPIO port D RCC enable
    RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIODEN_Pos);

    // reset input/output mode and set to alternate function (AF) mode
    GPIOD->MODER &= ~(GPIO_MODER_MODER8_Msk | GPIO_MODER_MODER9_Msk);
    GPIOD->MODER |= (0b10 << GPIO_MODER_MODER8_Pos) | (0b10 << GPIO_MODER_MODER9_Pos);

    // reset GPIO AF selection (0 and 1 of high AF register are pins 8 and 9), then choose AF7 for USART3
    GPIOD->AFR[1] &= ~(GPIO_AFRH_AFRH0 | GPIO_AFRH_AFRH1);
    GPIOD->AFR[1] |= (0b0111 << GPIO_AFRH_AFRH0_Pos) | (0b0111 << GPIO_AFRH_AFRH1_Pos);

    // BRR is 25 Mhz/115200 baud = 217
    USART3->BRR = 217;
    // usart enable and transmitter enable
    USART3->CR1 |= USART_CR1_UE | USART_CR1_TE;
}

void usart_write(USART_TypeDef *usart, char c)
{
    // write character to transmission data register
    usart->TDR = c;
    // wait on transmission complete bit
    while (!(usart->ISR & USART_ISR_TC))
        ;
}

void SPI_init()
{
    // checklist in 35.5.7
    //  SPI4 on PE11-14 (APB2)
    // enable SPI4 at RCC
    RCC->APB2ENR |= (1 << RCC_APB2ENR_SPI4EN_Pos);
    volatile uint32_t a = RCC->APB2ENR;
    a = RCC->APB2ENR;

    // GPIO port E RCC enable
    RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOEEN_Pos);
    volatile uint32_t b = RCC->APB2ENR;
    b = RCC->APB2ENR;

    // reset input/output mode and set to alternate function (AF) mode
    GPIOE->MODER &= ~(GPIO_MODER_MODER11_Msk | GPIO_MODER_MODER12_Msk | GPIO_MODER_MODER13_Msk | GPIO_MODER_MODER14_Msk);
    GPIOE->MODER |= (0b10 << GPIO_MODER_MODER11_Pos) | (0b10 << GPIO_MODER_MODER12_Pos) | (0b10 << GPIO_MODER_MODER13_Pos) | (0b10 << GPIO_MODER_MODER14_Pos);

    // reset GPIO AF selection (3 through 6 of high AF register are pins 11-14), then choose AF5 for SPI4
    GPIOE->AFR[1] &= ~(GPIO_AFRH_AFRH3 | GPIO_AFRH_AFRH4 | GPIO_AFRH_AFRH5 | GPIO_AFRH_AFRH6);
    GPIOE->AFR[1] |= (0b101 << GPIO_AFRH_AFRH3_Pos) | (0b101 << GPIO_AFRH_AFRH4_Pos) | (0b101 << GPIO_AFRH_AFRH5_Pos) | (0b101 << GPIO_AFRH_AFRH6_Pos);

    SPI4->CR1 |= SPI_CR1_MSTR;
    SPI4->CR2 |= SPI_CR2_SSOE;


    SPI4->CR1 |= SPI_CR1_SPE;

    uint8_t here = 'a';
    SPI_write(SPI4, &here, 0);


}

void SPI_write(SPI_TypeDef* tx_spi, uint8_t * tx_data, uint32_t tx_len){
    while (1)
    {
        printf("%i \r\n", tx_spi->SR);

        tx_spi->CR1 |= SPI_CR1_SPE;
        //tx_spi->CR1 |= SPI_CR1_SSI;
        //tx_spi->DR = *((uint8_t *) tx_data);
        //tx_spi->DR = *((uint16_t *)tx_data);

        uint32_t a = 'a';
        tx_spi->DR = a;
        //tx_spi->DR = 'a';
        
        while (!(tx_spi->SR & SPI_SR_BSY) & !(tx_spi->SR & SPI_SR_FTLVL))
        {
        }
        tx_spi->CR1 &= ~(SPI_CR1_SPE);
        //tx_spi->CR1 &= ~(SPI_CR1_SSI);

        delay_ms(1000);
        blink();
    }
}

void plainold()
{
    RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOEEN_Pos);

    GPIOE->MODER |= (1 << GPIO_MODER_MODER11_Pos);

    while (1)
    {
        GPIOE->ODR ^= (1 << GPIO_ODR_OD11_Pos);
        delay_ms(100);
    }
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
    // plainold();

    while (1)
    {
        uint8_t txs[] = "hi";
        printf("[%.3f] \r\n", (float)ticks / 1000.0f);
        blink();
        delay_ms(500);
    }
}
