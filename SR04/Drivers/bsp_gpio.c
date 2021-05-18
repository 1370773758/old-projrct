#include "bsp_gpio.h"
/* 
新驱动所用的IO口定义
*/

void AIN_GPIO(void)
{
	GPIO_InitTypeDef GPIO_AIN_init;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD,ENABLE);
	
	GPIO_AIN_init.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_AIN_init.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_AIN_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_AIN_init);
	
	GPIO_AIN_init.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_AIN_init.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_AIN_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_AIN_init);
	
	GPIO_AIN_init.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 ;
	GPIO_AIN_init.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_AIN_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_AIN_init);
	
	GPIO_AIN_init.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_AIN_init.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_AIN_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_AIN_init);
	
//	AIN_A4_OFF;
//	AIN_A5_OFF;
//	AIN_B4_OFF;
//	AIN_B5_OFF; CX
//	AIN_C2_OFF;
//	AIN_C3_OFF;
//	AIN_D1_OFF;
//	AIN_D2_OFF;
}
