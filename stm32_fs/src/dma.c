#include "stm32f767xx.h"
#include "system_stm32f7xx.h"
#include "dma.h"
#include <stdio.h>

void DMA2_channel_init()
{
    RCC->AHB1ENR |= (RCC_AHB1ENR_DMA2EN);
}

void DMA2_transfer(uint32_t *src, uint32_t *dst, uint32_t size)
{

    // instructions in 8.3.18
    // 1. disable DMA while setting flags
    DMA2_Stream0->CR &= ~(DMA_SxCR_EN);
    // transfer unit size is 1 byte by default (msize)
    // 2. set src ptr
    DMA2_Stream0->PAR = (uint32_t)src;  //gcc wants this to be a uin32_t but it is an address
    // 3. set dst ptr
    DMA2_Stream0->M0AR = (uint32_t)dst; //gcc wants this to be a uin32_t but it is an address
    // 4. set number of data
    DMA2_Stream0->NDTR = size;
    // 5. channel request CHSEL is 0 by default
    // 6. DMA is controller (for mem-to-mem) by default (not peripheral)
    // 7. priority is low by default
    // 8. ?
    // 9. increment src and dst pointers,mset CR to '10' memory-to-memory mode
    DMA2_Stream0->CR |= DMA_SxCR_MINC | DMA_SxCR_PINC | DMA_SxCR_DIR_1;
    // clear interrupt flags before enabling (8.5.5)
    DMA2->LIFCR |= DMA_LIFCR_CTCIF0 | DMA_LIFCR_CHTIF0;
    // 10. start transfer
    DMA2_Stream0->CR |= DMA_SxCR_EN;

    // since this is polling, wait until transfer is over (8.3.7)
    while (DMA2_Stream0->NDTR)
    {
    }
}

void using_dma()
{
    uint8_t tx_buffer_src1[] = "12345 \r\n";
    uint8_t tx_buffer_src2[] = "abcde \r\n";

    uint8_t tx_buffer_dst[] = "54321 \r\n";

    //printf("%i %i \r\n", DMA2->LISR, DMA2->HISR);

    printf("%s", tx_buffer_dst);
    DMA2_transfer((uint32_t *)tx_buffer_src1, (uint32_t *)tx_buffer_dst, 6);

    printf("%s", tx_buffer_dst);
    DMA2_transfer((uint32_t *)tx_buffer_src2, (uint32_t *)tx_buffer_dst, 6);

    printf("%s", tx_buffer_dst);


}