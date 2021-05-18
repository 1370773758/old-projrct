#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H

#include <stdbool.h>
#include <stdint.h>

//#if defined ( __CC_ARM   )
//#pragma anon_unions
//#endif
/* PID���� */
typedef struct
{
	float Target; 			        //�趨Ŀ��ֵ
	float Measured; 			    //����ֵ
	float err; 						//����ƫ��ֵ
	float err_last; 			    //��һ��ƫ��
	float err_beforeLast; 			//���ϴ�ƫ��
//	float Kp, Ki, Kd;				//Kp, Ki, Kd����ϵ��
	float pwm; 						//pwm���
	uint32_t MaxOutput;				//����޷�
	uint32_t IntegralLimit;			//�����޷� 
}incrementalpid_t;                  //����ʽincrementalpid_t

typedef struct
{
	float Target2; 			        //�趨Ŀ��ֵ
	float err2; 						//����ƫ��ֵ
	float err_last2; 			    //��һ��ƫ��
	float err_beforeLast2; 			//���ϴ�ƫ��
	float pwm2; 						//pwm���
  float Target3; 			        //�趨Ŀ��ֵ
	float err3; 						//����ƫ��ֵ
	float err_last3; 			    //��һ��ƫ��
	float err_beforeLast3; 			//���ϴ�ƫ��
	float pwm3; 						//pwm���
	 float Target4; 			        //�趨Ŀ��ֵ
	float err4; 						//����ƫ��ֵ
	float err_last4; 			    //��һ��ƫ��
	float err_beforeLast4; 			//���ϴ�ƫ��
	float pwm4; 						//pwm���
}pw;                  
//typedef struct
//{
//	float kp1;
//	float ki1;
//	float kd1;
//	float kp2;
//	float ki2;
//	float kd2;
//}pid;							//λ��ʽ

/* ң�� */
//typedef struct
//{
//	struct
//	{
//		int16_t ch0;
//		int16_t ch1;
//		int16_t ch2;
//		int16_t ch3;

//		uint8_t s_left;
//		uint8_t s_right;
//	}rc;

//	struct
//	{
//		int16_t x;
//		int16_t y;
//		int16_t z;

//		uint8_t keyLeft;
//		uint8_t keyRight;
//	}mouse;

//	union
//	{
//		uint16_t key_code;
//		struct
//		{
//			bool press_W : 1;
//			bool press_S : 1;
//			bool press_A : 1;
//			bool press_D : 1;
//			bool press_Shift : 1;
//			bool press_Ctrl : 1;
//			bool press_Q : 1;
//			bool press_E : 1;

//			bool press_R : 1;
//			bool press_F : 1;
//			bool press_G : 1;
//			bool press_Z : 1;
//			bool press_X : 1;
//			bool press_C : 1;
//			bool press_V : 1;
//			bool press_B : 1;
//		};
//	}keyBoard;

//	uint16_t DR16InfoUpdateFrame;	//֡��
//	uint8_t DR16OffLineFlag;	  	//�豸���߱�־

//}DR16_DBUS_DATA_t;


//typedef enum
//{
//	ControlMode_ByRC = 3,   //ң��
//	ControlMode_ByPC = 1,   //����
//	ControlMode_OFF = 2,
//}ControlMode_e;

//typedef enum
//{
//	ControlMode_Mid = 3,
//	ControlMode_High = 2,
//	ControlMode_Low = 1,
//}Mode_e;

//typedef enum
//{
//	SpecialMode_Normal = 0,
//	SpecialMode_BigSymbol = 2,	  //���ģʽ
//	SpecialMode_UPBridge = 3,	  //����ģʽ
//	SpecialMode_Supply = 4, 	  //����վģʽ
//}SpecialMode_t;

//typedef struct
//{
//	uint8_t ControlLeft;
//	uint8_t ControlRight;		  //����ģʽ
//}ControlStatus_t;

//typedef struct
//{
//	float x;
//	float y;
//	float radian;
//	float degrees;
//	float distance;
//}rocker_t;

#endif /* __TYPEDEFS_H */
