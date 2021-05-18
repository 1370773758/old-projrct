#include "SR04.h"

	float Distance ;

void SR04_Cfg(void)
{
	GPIO_InitTypeDef  GPIO_InitSture;
	EXTI_InitTypeDef  EXTI_InitSture;
	//����ⲿ�жϵĻ���һ��ʹ��AFIO���ù���
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOB,ENABLE);
	
	
	//����IO�˿�
	GPIO_InitSture.GPIO_Mode=GPIO_Mode_Out_PP;   //�������ģʽ
	GPIO_InitSture.GPIO_Pin=GPIO_Pin_0;                //��PE4��Trig����
	GPIO_InitSture.GPIO_Speed=GPIO_Speed_50MHz;  
	GPIO_Init(GPIOB,&GPIO_InitSture);
	
	GPIO_InitSture.GPIO_Mode=GPIO_Mode_IPD;      //������ģʽ
	GPIO_InitSture.GPIO_Pin=GPIO_Pin_1;                //��PE6��Echo����
	GPIO_InitSture.GPIO_Speed=GPIO_Speed_50MHz;  
	GPIO_Init(GPIOB,&GPIO_InitSture);
	
	//�жϺ�6�˿�ӳ��һ��
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
	
	//�ⲿ�ж�����
	EXTI_InitSture.EXTI_Line=EXTI_Line1;
	EXTI_InitSture.EXTI_LineCmd=ENABLE;
	EXTI_InitSture.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitSture.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitSture);
	
	NVIC_Config(EXTI1_IRQn,1,1);
}

void my_delay_ms(u32 ms)
{//����stm32f1ϵ�� 72mhz������1ms
		u16 i = 0;
		while(ms--)
		{
			i = 4050;
			while(i--);
		};
}
void my_delay_us(u32 us)
{//����stm32f1ϵ�� 72mhz������1us
		u16 i = 0;
		while(us--)
		{
			i = 2;
			while(i--);
		}
}
