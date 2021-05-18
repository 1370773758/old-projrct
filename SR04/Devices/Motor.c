
#include "Motor.h"



void TIM3_CounterMode(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitSture;   
	/* 配置时基结构体 */
	
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//使能TIM3
	
	//初始化定时器	
	TIM_TimeBaseInitSture.TIM_Period=5000;
	TIM_TimeBaseInitSture.TIM_Prescaler=7199;
	TIM_TimeBaseInitSture.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitSture.TIM_ClockDivision=0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitSture);
	
	//允许更新中断，触发方式中断
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_ITConfig(TIM3,TIM_IT_Trigger,ENABLE);
	
	NVIC_Config(TIM3_IRQn, 0, 1);
	/*配置中断优先级*/
//	TIM_Cmd(TIM3, ENABLE);
	//使能定时器
}



