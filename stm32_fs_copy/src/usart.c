#include "usart.h"

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