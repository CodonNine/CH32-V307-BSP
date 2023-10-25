/********************************** (C) COPYRIGHT *******************************
 * File Name          : ch32v30x_it.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : Main Interrupt Service Routines.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/
#include "ch32v30x_it.h"
#include "debug.h"
#include "dma.h"
#include "LCD/lcd.h"
#include "usart.h"
void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM1_UP_IRQHandler() __attribute__((interrupt("WCH-Interrupt-fast")));
void ADC1_2_IRQHandler() __attribute__((interrupt("WCH-Interrupt-fast")));
void DMA1_Channel1_IRQHandler() __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM3_IRQHandler() __attribute__((interrupt("WCH-Interrupt-fast")));
void USART1_IRQHandler() __attribute__((interrupt("WCH-Interrupt-fast")));
/*********************************************************************
 * @fn      NMI_Handler
 *
 * @brief   This function handles NMI exception.
 *
 * @return  none
 */
void NMI_Handler(void) {
}

/*********************************************************************
 * @fn      HardFault_Handler
 *
 * @brief   This function handles Hard Fault exception.
 *
 * @return  none
 */
void HardFault_Handler(void) {
    while (1)
    {
    }
}


void EXTI0_IRQHandler()
{
    if (EXTI_GetITStatus(EXTI_Line0) != RESET)
    {
        Delay_Ms(5);
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)
        {
            SPI_I2S_SendData(SPI1, 0xaa);
        }
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

#define SAMPLE_TIMES 50
extern uint16_t DataBuf[DATA_LENGTH][DATA_NUM];
float adc_val_average;
float current=0.0;
uint32_t adc_val=0;
uint8_t i=0;

void TIM1_UP_IRQHandler()
{
    if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
    {
        TIM_ClearITPendingBit(TIM1, TIM_IT_Update);

    }
}

void TIM3_IRQHandler()
{
    if(TIM_GetITStatus(TIM3, TIM_IT_Update)==SET)
    {
        printf("abcdefg\r\n");
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    }
}

//uint16_t adc_data;
//void ADC1_2_IRQHandler()
//{
//    if(ADC_GetITStatus(ADC1, ADC_IT_EOC)==SET)
//    {
//        adc_data=ADC_GetConversionValue(ADC1);//Get ADC conversion value
//        ADC_ClearITPendingBit(ADC1, ADC_IT_EOC);//Clear IT flag
//    }
//}
//

void DMA1_Channel1_IRQHandler()
{
    DMA_ClearITPendingBit(DMA1_IT_TC1);
    //static int i=0;

    for (i = 0; i < SAMPLE_TIMES; i++)
    {
        adc_val = adc_val + DataBuf[i][1];

    }
    adc_val_average = (float)adc_val / SAMPLE_TIMES;
    current = (adc_val_average / 4096 * 3.3) * 2000;
    printf("current=%.2f\r\n",adc_val_average);
    adc_val = 0;
//  printf("complete\r\n");
//    for(i=0;i<DATA_LENGTH;i++)
//    {
//        printf("buffer[%d][0]=%d,buffer[%d][1]=%d\r\n",i,DataBuf[i][0],i,DataBuf[i][1]);
//    }

}


void USART1_IRQHandler()
{
    if(USART_GetITStatus(USART1, USART_IT_IDLE)==SET)
    {
        USART_GetFlagStatus(USART1,USART_FLAG_IDLE);
        USART_ReceiveData(USART1);
        //U0_printf("%d",U1_Rx_Buff[0]);
        U1_Ctrl_Struct.RX_count+=USART1_RX_MAX+1-DMA_GetCurrDataCounter(DMA1_Channel5);
        U1_Ctrl_Struct.RX_In->end=&U1_Rx_Buff[U1_Ctrl_Struct.RX_count-1];
        U1_Ctrl_Struct.RX_In++;
        if(U1_Ctrl_Struct.RX_In==U1_Ctrl_Struct.RX_End)
        {
            U1_Ctrl_Struct.RX_In=&U1_Ctrl_Struct.RX_Data_Ptr[0];
        }
        if(USART1_RX_SIZE-U1_Ctrl_Struct.RX_count>=USART1_RX_MAX)
        {
            U1_Ctrl_Struct.RX_In->start=&U1_Rx_Buff[U1_Ctrl_Struct.RX_count];
        }
        else
        {
            U1_Ctrl_Struct.RX_In->start=U1_Rx_Buff;
        }

        DMA_Cmd(DMA1_Channel5, DISABLE);
        DMA_SetCurrDataCounter(DMA1_Channel5,USART1_RX_MAX+1);
        DMA1_Channel5->MADDR=(uint32_t)U1_Ctrl_Struct.RX_In->start;
        DMA_Cmd(DMA1_Channel5, ENABLE);
        U0_printf("IN:%x\r\n",U1_Ctrl_Struct.RX_In);
        U0_printf("OUT:%x\r\n",U1_Ctrl_Struct.RX_Out);
    }
}
















