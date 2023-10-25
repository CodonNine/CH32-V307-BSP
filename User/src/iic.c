#include "ch32v30x.h"
#include "iic.h"
#include "usart.h"
void IIC_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructer;
    GPIO_InitStructer.GPIO_Mode=GPIO_Mode_Out_OD;
    GPIO_InitStructer.GPIO_Pin=IIC_SCL_PIN|IIC_SDA_PIN;
    GPIO_InitStructer.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(IIC_PORT, &GPIO_InitStructer);

    IIC_SCL_H;
    IIC_SDA_H;
}

void IIC_In()
{
    GPIO_InitTypeDef GPIO_InitStructer;
    GPIO_InitStructer.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_InitStructer.GPIO_Pin=IIC_SCL_PIN|IIC_SDA_PIN;
    GPIO_InitStructer.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(IIC_PORT, &GPIO_InitStructer);
}

void IIC_Start()
{
    IIC_SCL_H;
    IIC_SDA_H;
    Delay_Us(2);
    IIC_SDA_L;
    Delay_Us(2);
    IIC_SCL_L;
}

void IIC_Stop()
{
    IIC_SCL_H;
    IIC_SDA_L;
    Delay_Us(2);
    IIC_SDA_H;
}

void IIC_Send_Byte(uint8_t data)
{
    uint8_t i;
    for(i=0;i<8;i++)
    {
        IIC_SCL_L;
        if((data & 0x80)==0x80) IIC_SDA_H;
        else if((data & 0x80)==0) IIC_SDA_L;
        Delay_Us(1);
        IIC_SCL_H;
        data<<=1;
        Delay_Us(2);
    }
    IIC_SCL_L;
    IIC_SDA_H;
}


uint8_t IIC_Wait_Ack(uint16_t timeout)
{
    IIC_SCL_H;
    while(GPIO_ReadInputDataBit(IIC_PORT, IIC_SDA_PIN)!=RESET)
    {
        timeout--;
        Delay_Us(1);
        if(timeout==0) break;
    }
    if(timeout==0)
    {
        return 1;
    }
    IIC_SCL_H;
    Delay_Us(2);
    if(GPIO_ReadInputDataBit(IIC_PORT, IIC_SDA_PIN)) return 2;
    IIC_SCL_L;
    Delay_Us(2);
    return 0;
}


uint8_t IIC_Read_Byte(uint8_t ack)
{
    uint8_t i;
    uint8_t byte=0x00;
    for(i=0;i<8;i++)
    {
        IIC_SCL_L;
        Delay_Us(2);
        IIC_SCL_H;
        if(GPIO_ReadInputDataBit(IIC_PORT, IIC_SDA_PIN)==SET) byte|=0x01;
        else if(GPIO_ReadInputDataBit(IIC_PORT, IIC_SDA_PIN)==RESET) byte|=0x00;
        byte<<=1;
        Delay_Us(2);
    }
    IIC_SCL_L;
    Delay_Us(2);
    if(ack)
    {
        IIC_SDA_L;
        IIC_SCL_H;
        Delay_Us(2);
        IIC_SCL_L;
        IIC_SDA_H;
        Delay_Us(2);
    }
    else
    {
        IIC_SDA_H;
        IIC_SCL_H;
        Delay_Us(2);
        IIC_SCL_L;
        Delay_Us(2);
    }

    return byte;
}
