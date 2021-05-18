#include "SR04.h"

	float Distance ;

void SR04_Cfg(void)
{
	GPIO_InitTypeDef  GPIO_InitSture;
	EXTI_InitTypeDef  EXTI_InitSture;
	//如果外部中断的话则一定使能AFIO复用功能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOB,ENABLE);
	
	
	//配置IO端口
	GPIO_InitSture.GPIO_Mode=GPIO_Mode_Out_PP;   //推挽输出模式
	GPIO_InitSture.GPIO_Pin=GPIO_Pin_0;                //将PE4于Trig相连
	GPIO_InitSture.GPIO_Speed=GPIO_Speed_50MHz;  
	GPIO_Init(GPIOB,&GPIO_InitSture);
	
	GPIO_InitSture.GPIO_Mode=GPIO_Mode_IPD;      //拉输入模式
	GPIO_InitSture.GPIO_Pin=GPIO_Pin_1;                //将PE6于Echo相连
	GPIO_InitSture.GPIO_Speed=GPIO_Speed_50MHz;  
	GPIO_Init(GPIOB,&GPIO_InitSture);
	
	//中断和6端口映射一起
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
	
	//外部中断配置
	EXTI_InitSture.EXTI_Line=EXTI_Line1;
	EXTI_InitSture.EXTI_LineCmd=ENABLE;
	EXTI_InitSture.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitSture.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitSture);
	
	NVIC_Config(EXTI1_IRQn,1,1);
}

void my_delay_ms(u32 ms)
{//对于stm32f1系列 72mhz大致是1ms
		u16 i = 0;
		while(ms--)
		{
			i = 4050;
			while(i--);
		};
}
void my_delay_us(u32 us)
{//对于stm32f1系列 72mhz大致是1us
		u16 i = 0;
		while(us--)
		{
			i = 2;
			while(i--);
		}
}
