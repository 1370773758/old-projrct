/*
  ******************************************************************************
  * @file    bsp_can.c
  * @author   
  * @version  
  * @date    
  * @brief   �ص�ģ���ʹ��
  ******************************************************************************
  */

#include "bsp_can.h"

u8 flag=0;

CanTxMsg  CANTX;
CanRxMsg  CANRX;

void can_cfg(void)
{
	GPIO_InitTypeDef      gpio_init;
	CAN_InitTypeDef       can_init;
	CAN_FilterInitTypeDef can_filterinit; // �������Ľṹ��
	
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA,ENABLE );
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_CAN1 ,ENABLE );//ʹ�� CAN1 ʱ��
	
	gpio_init.GPIO_Pin=GPIO_Pin_11;
	gpio_init.GPIO_Mode=GPIO_Mode_IPU ;
	gpio_init.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&gpio_init);
	
	gpio_init.GPIO_Pin=GPIO_Pin_12;
	gpio_init.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA ,&gpio_init);
	
	//can��Ԫ���� ���ù���ģʽ CAN_Mode_LoopBack  CAN_Mode_Normal
	can_init.CAN_Mode=CAN_Mode_Normal;//�ػ�ģʽ����������Ϊ��ͨģʽ
	can_init.CAN_TTCM=DISABLE;			//��ʱ�䴥��ͨ��ģʽ  
	can_init.CAN_ABOM=ENABLE;			//����Զ����߹���	 
	can_init.CAN_AWUM=ENABLE;			//˯��ģʽͨ���������(���CAN->MCR��SLEEPλ)
	can_init.CAN_NART=DISABLE;			//���Ĵ����Զ����� 
	can_init.CAN_RFLM=DISABLE;		 	//���Ĳ�����,�µĸ��Ǿɵ�  
	can_init.CAN_TXFP=DISABLE;			//���ȼ��ɱ��ı�ʶ������ 
	//���ò����� 1Mbps SYNC_SE�ι̶���1Tq
	can_init.CAN_SJW =CAN_SJW_1tq;
	can_init.CAN_BS1= CAN_BS1_3tq;
	can_init.CAN_BS2= CAN_BS2_2tq;//bs1+bs2+se��=9Tq 153
	can_init.CAN_Prescaler=6;//�ڲ����Լ�1  4
	CAN_Init(CAN1 ,&can_init);
/* can������ */
	can_filterinit.CAN_FilterActivation=ENABLE; //�Ƿ�ʹ�ܹ�����
	can_filterinit.CAN_FilterFIFOAssignment=CAN_FilterFIFO0;//���ݴ���FIFO0
	can_filterinit.CAN_FilterNumber=0;//0��13 ������0
	can_filterinit.CAN_FilterScale=CAN_FilterScale_32bit;//16λ 32λ
	can_filterinit.CAN_FilterMode=CAN_FilterMode_IdMask;
	/* ���˵�����չ֡����չ����֡ */
	can_filterinit.CAN_FilterIdHigh= ((PASS_ID<<3|CAN_ID_EXT|CAN_RTR_Data)&0xFFFF0000)>>16 ;//���˵�ID0x0000;//((PASS_ID<<3|CAN_ID_EXT|CAN_RTR_Data)&0xFFFF0000)>>16
	can_filterinit.CAN_FilterIdLow=   ((PASS_ID<<3|CAN_ID_EXT|CAN_RTR_Data)&0xFFFF) ;//0x0000;// ((PASS_ID<<3|CAN_ID_EXT|CAN_RTR_Data)&0xFFFF)
	/*��չ����֡�ĵ�16λ������Ҫλ�� */
	can_filterinit.CAN_FilterMaskIdHigh=0x0000;//32λMASK0x01E0;// 
	can_filterinit.CAN_FilterMaskIdLow=0x0000;//������������0x0000;//
	CAN_FilterInit(&can_filterinit);			//�˲�����ʼ��

	NVIC_Config (USB_LP_CAN1_RX0_IRQn,0,0);//��������0
	/*�жϺ�����Ļ� �Ῠ�������ļ�*/
	CAN_ITConfig (CAN1 ,CAN_IT_FMP0,ENABLE );//CAN_IT_FMP0��������0�������ж�,ʹ���ж�
}

//void can_init(void)
//{

//}
