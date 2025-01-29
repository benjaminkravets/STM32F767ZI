#include "stm32f767xx.h"
#include "system_stm32f7xx.h"
#include "exti_gpio_irq.h"

#define LED_PIN 0

void exti_init()
{
    // instructions in 11.5 (and 4.2.2 of PM0253 M7 Programming manual)

    // GPIO port C RCC enable
    RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOCEN_Msk);
    // enable SYSCFG for managing EXTI lines
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN_Msk;
    // enable C13 pin EXTI (11.8)
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
    // 1. don't mask interrupt request from line 13 (event is EMR)
    EXTI->IMR |= EXTI_IMR_IM13;
    // 2. enable input line 13 rising edge detection (falling edge is FTSR)
    EXTI->RTSR |= EXTI_RTSR_TR13_Msk;
    // 3. ISER[1] is 32 - (56 - 32) (since this is past ISER[0])
    NVIC->ISER[1] |= (1 << 8);

    // original CMSIS
    // NVIC_EnableIRQ(EXTI15_10_IRQn);
    // NVIC->ISER[(((uint32_t)EXTI15_10_IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)EXTI15_10_IRQn) & 0x1FUL));

}

void exti15_10_handler()
{
    EXTI->PR |= (1 << 13);
    GPIOB->ODR ^= (1 << LED_PIN);
}