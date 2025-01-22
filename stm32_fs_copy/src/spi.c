#include "stm32f767xx.h"
#include "system_stm32f7xx.h"
#include "spi.h"
#include <stdio.h>

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
}

void SPI_write(SPI_TypeDef *tx_spi, uint8_t *tx_data, uint8_t *rx_data, uint32_t tx_len)
{

    printf("%i \r\n", tx_spi->SR);

    tx_spi->CR1 |= SPI_CR1_SPE;

    uint8_t *tx_data_cpy = tx_data;

    for (uint32_t i = 0; i < 4; i++)
    {

        while (!(tx_spi->SR & SPI_SR_TXE))
        {
        }
        tx_spi->DR = *((uint16_t *)tx_data_cpy);

        tx_data_cpy += 2;
    }

    // wait for transmit FIFO to be empty
    while ((tx_spi->SR & SPI_SR_FTLVL))
    {
    }
    // wait while SPI is busy
    while (tx_spi->SR & SPI_SR_BSY)
    {
    }

    tx_spi->CR1 &= ~(SPI_CR1_SPE);
    // tx_spi->CR1 &= ~(SPI_CR1_SSI);
}