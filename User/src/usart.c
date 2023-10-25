#include "ch32v30x.h"
#include "usart.h"

uint8_t U1_Rx_Buff[USART1_RX_SIZE];
uint8_t U1_Tx_Buff[USART1_TX_SIZE];
USART1_RX_Ctrl U1_Ctrl_Struct;

void USART1_DMA_Init()
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    DMA_InitTypeDef DMA_InitStructer;

    DMA_DeInit(DMA1_Channel1);

    DMA_InitStructer.DMA_BufferSize=USART1_RX_MAX+1;
    DMA_InitStructer.DMA_DIR=DMA_DIR_PeripheralSRC;//DMA direction:peripheral to memory
    DMA_InitStructer.DMA_M2M=DMA_M2M_Disable;
    DMA_InitStructer.DMA_MemoryBaseAddr=(uint32_t) U1_Rx_Buff;
    DMA_InitStructer.DMA_MemoryDataSize= DMA_MemoryDataSize_Byte;
    DMA_InitStructer.DMA_MemoryInc=DMA_MemoryInc_Enable;
    DMA_InitStructer.DMA_Mode=DMA_Mode_Normal;
    DMA_InitStructer.DMA_PeripheralBaseAddr=(uint32_t) &USART1->DATAR;
    DMA_InitStructer.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
    DMA_InitStructer.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
    DMA_InitStructer.DMA_Priority=DMA_Priority_High;
    DMA_Init(DMA1_Channel5,&DMA_InitStructer);

    DMA_Cmd(DMA1_Channel5, ENABLE);
}

void U1Rx_PtrInit()
{
    U1_Ctrl_Struct.RX_In=&U1_Ctrl_Struct.RX_Data_Ptr[0];
    U1_Ctrl_Struct.RX_Out=&U1_Ctrl_Struct.RX_Data_Ptr[0];
    U1_Ctrl_Struct.RX_End=&U1_Ctrl_Struct.RX_Data_Ptr[NUM-1];
    U1_Ctrl_Struct.RX_In->start=U1_Rx_Buff;
    U1_Ctrl_Struct.RX_In->end=U1_Rx_Buff;
    U1_Ctrl_Struct.RX_count=0;
}

void USART1_Init(uint32_t baudrate)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = baudrate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART1, &USART_InitStructure);
    U1Rx_PtrInit();
    USART1_DMA_Init();
    USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);
    USART_Cmd(USART1, ENABLE);


    USART_ITConfig(USART1,USART_IT_IDLE, ENABLE);
    NVIC_SetPriority(USART1_IRQn , 0x00);
    NVIC_EnableIRQ(USART1_IRQn);
}


void U0_printf(char *format,...)
{
    va_list listdata;
    va_start(listdata,format);
    vsprintf((char*)U1_Tx_Buff,format,listdata);
    va_end(listdata);

    for(int i=0;i<strlen((const char*)U1_Tx_Buff);i++)
    {
        while(USART_GetFlagStatus(USART1, USART_FLAG_TC)!=SET);
        USART_SendData(USART1, U1_Tx_Buff[i]);
    }
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE)!=SET);
}

