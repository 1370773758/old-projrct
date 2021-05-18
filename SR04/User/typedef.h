#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H

#include <stdbool.h>
#include <stdint.h>

//#if defined ( __CC_ARM   )
//#pragma anon_unions
//#endif
/* PID参数 */
typedef struct
{
	float Target; 			        //设定目标值
	float Measured; 			    //测量值
	float err; 						//本次偏差值
	float err_last; 			    //上一次偏差
	float err_beforeLast; 			//上上次偏差
//	float Kp, Ki, Kd;				//Kp, Ki, Kd控制系数
	float pwm; 						//pwm输出
	uint32_t MaxOutput;				//输出限幅
	uint32_t IntegralLimit;			//积分限幅 
}incrementalpid_t;                  //增量式incrementalpid_t

typedef struct
{
	float Target2; 			        //设定目标值
	float err2; 						//本次偏差值
	float err_last2; 			    //上一次偏差
	float err_beforeLast2; 			//上上次偏差
	float pwm2; 						//pwm输出
  float Target3; 			        //设定目标值
	float err3; 						//本次偏差值
	float err_last3; 			    //上一次偏差
	float err_beforeLast3; 			//上上次偏差
	float pwm3; 						//pwm输出
	 float Target4; 			        //设定目标值
	float err4; 						//本次偏差值
	float err_last4; 			    //上一次偏差
	float err_beforeLast4; 			//上上次偏差
	float pwm4; 						//pwm输出
}pw;                  
//typedef struct
//{
//	float kp1;
//	float ki1;
//	float kd1;
//	float kp2;
//	float ki2;
//	float kd2;
//}pid;							//位置式

/* 遥控 */
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

//	uint16_t DR16InfoUpdateFrame;	//帧率
//	uint8_t DR16OffLineFlag;	  	//设备离线标志

//}DR16_DBUS_DATA_t;


//typedef enum
//{
//	ControlMode_ByRC = 3,   //遥控
//	ControlMode_ByPC = 1,   //电脑
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
//	SpecialMode_BigSymbol = 2,	  //大符模式
//	SpecialMode_UPBridge = 3,	  //上桥模式
//	SpecialMode_Supply = 4, 	  //补给站模式
//}SpecialMode_t;

//typedef struct
//{
//	uint8_t ControlLeft;
//	uint8_t ControlRight;		  //特殊模式
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
