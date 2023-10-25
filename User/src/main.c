/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 USART Print debugging routine:
 USART1_Tx(PA9).
 This example demonstrates using USART1(PA9) as a print debug port output.

 */

#include "debug.h"
#include "LCD/lcd_init.h"
#include "LCD/lcd.h"
#include "LCD/pic.h"
//#include "adc.h"
//#include "dma.h"
//#include "tim.h"
//#include "nvic.h"
//#include "spi.h"
//#include "W25Q/w25q.h"
#include "usart.h"
#include "iic.h"
#include "AT24CX/at24cx.h"
/* Global typedef */

/* Global define */

/* Global Variable */

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    uint16_t i;
//    extern float current;
//    char current_data[10];
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    USART1_Init(115200);
    Delay_Init();
    IIC_Init();
    for(i=0;i<256;i++)
    {
        AT24CX_Write_Byte(i, i);
        Delay_Ms(5);
        U0_printf("传送了%d个数据\r\n",i+1);
    }
//    IIC_Start();
//    IIC_Send_Byte(0xa0);
//    IIC_Stop();
    //U0_printf("%d",GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11));
    while(1)
    {
//        //U0_printf("%d\r\n",12345);
//        //Delay_Ms(1);
//
//        if(U1_Ctrl_Struct.RX_Out!=U1_Ctrl_Struct.RX_In)
//        {
//            U0_printf("接受了%d个数据\r\n",U1_Ctrl_Struct.RX_Out->end-U1_Ctrl_Struct.RX_Out->start+1);
//            for(int i=0;i<U1_Ctrl_Struct.RX_Out->end-U1_Ctrl_Struct.RX_Out->start+1;i++)
//            {
//                U0_printf("%c",U1_Ctrl_Struct.RX_Out->start[i]);
//
//            }
//            U0_printf("\r\n");
//            U1_Ctrl_Struct.RX_Out++;
//            if(U1_Ctrl_Struct.RX_Out==U1_Ctrl_Struct.RX_End)
//            {
//                U1_Ctrl_Struct.RX_Out=&U1_Ctrl_Struct.RX_Data_Ptr[0];
//            }
//        }
//
//        Delay_Us(1);
    }
}

