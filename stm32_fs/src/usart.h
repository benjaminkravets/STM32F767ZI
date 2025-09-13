#include "stm32f7xx.h"

void USART3_init();
void usart_write(USART_TypeDef *usart, char c);
char usart_read(USART_TypeDef* usart);
