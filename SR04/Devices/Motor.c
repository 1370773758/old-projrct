
#include "Motor.h"



void TIM3_CounterMode(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitSture;   
	/* ����ʱ���ṹ�� */
	
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//ʹ��TIM3
	
	//��ʼ����ʱ��	
	TIM_TimeBaseInitSture.TIM_Period=5000;
	TIM_TimeBaseInitSture.TIM_Prescaler=7199;
	TIM_TimeBaseInitSture.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitSture.TIM_ClockDivision=0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitSture);
	
	//��������жϣ�������ʽ�ж�
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_ITConfig(TIM3,TIM_IT_Trigger,ENABLE);
	
	NVIC_Config(TIM3_IRQn, 0, 1);
	/*�����ж����ȼ�*/
//	TIM_Cmd(TIM3, ENABLE);
	//ʹ�ܶ�ʱ��
}



