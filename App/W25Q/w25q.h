#ifndef W25Q_H
#define W25Q_H
#include "ch32v30x.h"

#define W25X_WriteEnable         0x06
#define W25X_WriteDisable        0x04
#define W25X_ReadStatusReg       0x05
#define W25X_WriteStatusReg      0x01
#define W25X_ReadData            0x03
#define W25X_FastReadData        0x0B
#define W25X_FastReadDual        0x3B
#define W25X_PageProgram         0x02
#define W25X_BlockErase          0xD8
#define W25X_SectorErase         0x20
#define W25X_ChipErase           0xC7
#define W25X_PowerDown           0xB9
#define W25X_ReleasePowerDown    0xAB
#define W25X_DeviceID            0xAB
#define W25X_ManufactDeviceID    0x90
#define W25X_JedecDeviceID       0x9F

#define CS_PIN  GPIO_Pin_8
#define CS_PORT GPIOB

#define W25Q_CS_HIGH GPIO_SetBits(CS_PORT,CS_PIN)
#define W25Q_CS_LOW  GPIO_ResetBits(CS_PORT,CS_PIN)

void W25Q_Init();
uint16_t W25Q_ReadID();
#endif
