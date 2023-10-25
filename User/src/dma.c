#include "ch32v30x.h"
#include "dma.h"


uint16_t DataBuf[DATA_LENGTH][DATA_NUM];

void DMA_Config()
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    DMA_InitTypeDef DMA_InitStructer;

    DMA_DeInit(DMA1_Channel1);

    DMA_InitStructer.DMA_BufferSize=DATA_LENGTH*DATA_NUM;
    DMA_InitStructer.DMA_DIR=DMA_DIR_PeripheralSRC;//DMA direction:peripheral to memory
    DMA_InitStructer.DMA_M2M=DMA_M2M_Disable;
    DMA_InitStructer.DMA_MemoryBaseAddr=(uint32_t) DataBuf;
    DMA_InitStructer.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;
    DMA_InitStructer.DMA_MemoryInc=DMA_MemoryInc_Enable;
    DMA_InitStructer.DMA_Mode=DMA_Mode_Circular;
    DMA_InitStructer.DMA_PeripheralBaseAddr=(uint32_t) &ADC1->RDATAR;
    DMA_InitStructer.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructer.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
    DMA_InitStructer.DMA_Priority=DMA_Priority_High;
    DMA_Init(DMA1_Channel1,&DMA_InitStructer);

    DMA_Cmd(DMA1_Channel1, ENABLE);

    DMA_ITConfig(DMA1_Channel1, DMA_IT_TC , ENABLE);
    NVIC_SetPriority(DMA1_Channel1_IRQn, 0x00);
    NVIC_EnableIRQ(DMA1_Channel1_IRQn);
}
