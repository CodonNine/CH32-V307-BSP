#ifndef USART_H
#define USART_H

#include "ch32v30x.h"
#include "stdarg.h"
#include "string.h"

#define USART1_RX_SIZE     2048
#define USART1_TX_SIZE     1000
#define USART1_RX_MAX      256
#define NUM                10

typedef struct
{
    uint8_t* start;
    uint8_t* end;
}USART1_RXBuff_Ptr;

typedef struct
{
    uint16_t RX_count;
    USART1_RXBuff_Ptr RX_Data_Ptr[NUM];
    USART1_RXBuff_Ptr* RX_In;
    USART1_RXBuff_Ptr* RX_Out;
    USART1_RXBuff_Ptr* RX_End;
}USART1_RX_Ctrl;

extern USART1_RX_Ctrl U1_Ctrl_Struct;
extern uint8_t U1_Rx_Buff[USART1_RX_SIZE];


void U0_printf(char *format,...);
void USART1_Init(uint32_t baudrate);
#endif

