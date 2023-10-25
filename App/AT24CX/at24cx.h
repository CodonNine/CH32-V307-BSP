#ifndef AT24CX_H
#define AT24CX_H

#define AT24C02_WADDR 0XA0
#define AT24C02_RADDR 0XA1
#define TIMEOUT 500
uint8_t AT24CX_Write_Byte(uint8_t addr,uint8_t data);
uint8_t AT24CX_Write_Page(uint8_t addr,uint8_t* data);
uint8_t AT24CX_Read_Data(uint8_t addr,uint8_t* data,uint8_t len);
#endif
