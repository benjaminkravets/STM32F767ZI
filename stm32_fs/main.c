#include "stm32f767xx.h"
#include <stdint.h>


#define LED_PIN 0

int main()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN_Msk;
    volatile uint32_t dummy;

    GPIOB->MODER |= (1 << GPIO_MODER_MODER0_Pos);

    while (1)
    {
        GPIOB->ODR ^= (1 << LED_PIN);
        for (uint32_t i = 0; i < 1000000; i++){

        };
    }
}