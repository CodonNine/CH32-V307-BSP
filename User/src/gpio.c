#include "ch32v30x.h"

void LED_GPIO_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_Initstructer;

    GPIO_Initstructer.GPIO_Mode=GPIO_Mode_Out_PP;
    GPIO_Initstructer.GPIO_Pin=GPIO_Pin_15;
    GPIO_Initstructer.GPIO_Speed=GPIO_Speed_50MHz;

    GPIO_Init(GPIOA,&GPIO_Initstructer);
}


void Key_GPIO_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_Initstructer;

    GPIO_Initstructer.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_Initstructer.GPIO_Pin=GPIO_Pin_12;
    GPIO_Initstructer.GPIO_Speed=GPIO_Speed_50MHz;

    GPIO_Init(GPIOA,&GPIO_Initstructer);
}


