#include "spi.h"
#include "ch32v30x.h"
#include "w25q.h"

void W25Q_Init()
{
    SPI2_Init();
}

uint16_t W25Q_ReadID()
{
    u16 Temp = 0;

    W25Q_CS_LOW;
    SPI2_Read_Write_Byte(W25X_ManufactDeviceID);
    SPI2_Read_Write_Byte(0x00);
    SPI2_Read_Write_Byte(0x00);
    SPI2_Read_Write_Byte(0x00);
    Temp |= SPI2_Read_Write_Byte(0xFF) << 8;
    Temp |= SPI2_Read_Write_Byte(0xFF);
    W25Q_CS_HIGH;

    return Temp;
}
