
#include <stdint.h>

#define PERIPHERAL_BASE (0x40000000U)
#define AHB1_BASE (PERIPHERAL_BASE + 0x20000U)
#define GPIOB_BASE (AHB1_BASE + 0x400U)
#define RCC_BASE (AHB1_BASE + 0x3800U)

#define RCC_AHB1ENR_OFFSET (0x30U) //peripheral clock register
#define RCC_AHB1ENR ((volatile uint32_t *)(RCC_BASE + RCC_AHB1ENR_OFFSET))
#define RCC_AHB1ENR_GPIOBEN (0x01U) //gpiob is at bit 1

#define GPIO_MODER_OFFSET (0x00U) //port mode register
#define GPIOB_MODER ((volatile uint32_t *)(GPIOB_BASE + GPIO_MODER_OFFSET))
#define GPIO_MODER_MODER0 (0U) //target pin 0
#define GPIO_ODR_OFFSET (0x14U) //output data register
#define GPIOB_ODR ((volatile uint32_t *)(GPIOB_BASE + GPIO_ODR_OFFSET))

#define LED_PIN 0

int main()
{
    *RCC_AHB1ENR |= (1 << RCC_AHB1ENR_GPIOBEN); //enable peripheral clock

    volatile uint32_t dummy;

    *GPIOB_MODER |= (1 << GPIO_MODER_MODER0); //set mode to general purpose output (push-pull by default)

    while (1)
    {
        *GPIOB_ODR ^= (1 << LED_PIN); //set output data register
        for (uint32_t i = 0; i < 1000000; i++)
            ;
    }
}
