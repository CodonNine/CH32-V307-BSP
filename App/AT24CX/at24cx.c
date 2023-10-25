#include "ch32v30x.h"
#include "iic.h"
#include "at24cx.h"
#include "usart.h"
uint8_t AT24CX_Write_Byte(uint8_t addr,uint8_t data)
{
    IIC_Start();

    IIC_Send_Byte(AT24C02_WADDR);
    Delay_Us(2);
    U0_printf("%d",GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11));
    if(IIC_Wait_Ack(TIMEOUT)!=0) return 1;

    IIC_Send_Byte(addr);
    if(IIC_Wait_Ack(TIMEOUT)!=0) return 2;

    IIC_Send_Byte(data);
    if(IIC_Wait_Ack(TIMEOUT)!=0) return 3;

    IIC_Stop();
    return 0;
}

uint8_t AT24CX_Write_Page(uint8_t addr,uint8_t* data)
{
    uint8_t i;

    IIC_Start();

    IIC_Send_Byte(AT24C02_WADDR);
    if(IIC_Wait_Ack(TIMEOUT)!=0) return 1;

    IIC_Send_Byte(addr);
    if(IIC_Wait_Ack(TIMEOUT)!=0) return 2;

    for(i=0;i<16;i++)
    {
        IIC_Send_Byte(data[i]);
        if(IIC_Wait_Ack(TIMEOUT)!=0) return 3+i;
    }

    IIC_Stop();
    return 0;
}

uint8_t AT24CX_Read_Data(uint8_t addr,uint8_t* data,uint8_t len)
{
    uint8_t i;

    IIC_Start();

    IIC_Send_Byte(AT24C02_WADDR);
    if (IIC_Wait_Ack(TIMEOUT) != 0) return 1;

    IIC_Send_Byte(addr);
    if (IIC_Wait_Ack(TIMEOUT) != 0) return 2;


    IIC_Start();

    IIC_Send_Byte(AT24C02_RADDR);
    if (IIC_Wait_Ack(TIMEOUT) != 0) return 2;
    for(i=0;i<len-1;i++)
    {
        data[i]=IIC_Read_Byte(1);
    }
    data[len-1]=IIC_Read_Byte(0);
    IIC_Stop();
    return 0;
}
