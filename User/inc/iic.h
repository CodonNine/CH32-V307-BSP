#ifndef IIC_H
#define IIC_H
#include "ch32v30x.h"

#define IIC_PORT        GPIOB
#define IIC_SCL_PIN     GPIO_Pin_10
#define IIC_SDA_PIN     GPIO_Pin_11

#define IIC_SCL_H   GPIO_SetBits(IIC_PORT, IIC_SCL_PIN)
#define IIC_SCL_L   GPIO_ResetBits(IIC_PORT, IIC_SCL_PIN)

#define IIC_SDA_H   GPIO_SetBits(IIC_PORT, IIC_SDA_PIN)
#define IIC_SDA_L   GPIO_ResetBits(IIC_PORT, IIC_SDA_PIN)

void IIC_Init();
void IIC_Start();
void IIC_Stop();
void IIC_Send_Byte(uint8_t data);
void IIC_In();

uint8_t IIC_Wait_Ack(uint16_t timeout);
uint8_t IIC_Read_Byte(uint8_t ack);
#endif
