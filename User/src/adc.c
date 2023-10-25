#include "ch32v30x.h"

void ADC_Config()
{
    /*ADC-GPIO config*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /*ADC config*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);// APB2=144/2=72MHz,ADC=APB2/6=12MHz;

    ADC_InitTypeDef ADC_InitStructure;
    ADC_InitStructure.ADC_ContinuousConvMode=DISABLE;
    ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;
    ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_T3_TRGO;
    ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;
    ADC_InitStructure.ADC_NbrOfChannel=2;
    ADC_InitStructure.ADC_OutputBuffer=ENABLE;
    ADC_InitStructure.ADC_ScanConvMode=ENABLE;
    ADC_Init(ADC1,&ADC_InitStructure);

    ADC_DMACmd(ADC1, ENABLE);
    ADC_TempSensorVrefintCmd(ENABLE);
    ADC_Cmd(ADC1, ENABLE);

    ADC_ExternalTrigConvCmd(ADC1, ENABLE);
}
