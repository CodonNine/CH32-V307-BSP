#ifndef SPI_H
#define SPI_H
#include "ch32v30x.h"

void SPI1_Init();
void SPI1_Write_Byte(uint16_t data);
uint8_t SPI2_Read_Write_Byte(uint8_t data);
void SPI2_Init();
void nop();
#endif
