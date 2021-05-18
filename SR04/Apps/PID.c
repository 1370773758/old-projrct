/*
  *******************************************************************************
  * @file    PID.c
  * @author  Luu-yy
  * @version  
  * @date    
  * @brief   PID功能函数
  ******************************************************************************
  */

#include "PID.h"

/*输出限幅*/
//void PWM_Limit(int motor)
//{
//	int Amplitude = 7200;
//    if(motor > Amplitude)
//		motor = Amplitude;
//    if(motor < -Amplitude)
//		motor = -Amplitude;
//}

/**
* @brief	     增量式PID-参数初始化(试过可用，位置式后来加上去要你们自己试试应该是没问题的）
* @param [in]    增量式PID指针
*				 [in] Kp   比例  主要是提高响应速度
*				 [in] Ki   积分  消除稳态误差
*				 [in] Kd   微分  抑制偏差
*				 具体解析可以看文档和自己百度慢慢摸索，调参很多时候还靠感觉
* @retval        
*/
 float kp1=17.5;//45.5
 float ki1=4.67;//24
 float kd1=4.8;//0.85

 float kp2=14;
 float ki2=4.2;
 float kd2=0;

float kp3=0;
float ki3=0;
float kd3=0;

float kp4=0;
float ki4=0;
float kd4=0;
int Incremental_PID(int Encoder1, int Target1)
{
	pid.err = Encoder1 - Target1;
	pid.pwm += kp1*(pid.err - pid.err_last) + ki1*pid.err + kd1*(pid.err - 2 * pid.err_last + pid.err_beforeLast);

	if (pid.pwm>7200)
		pid.pwm = 7100;
	else if (pid.pwm<-7200)
		pid.pwm = -7100;

	pid.err_beforeLast = pid.err_last;
	pid.err_last = pid.err;
	
	return pid.pwm;
}

int PID2(int Encoder2, int Target2)
{

	p.err2 = Encoder2 - Target2;
	p.pwm2 += kp2*(p.err2 - p.err_last2) + ki2*p.err2 + kd2*(p.err2 - 2 * p.err_last2 + p.err_beforeLast2);

	if (p.pwm2>7200)
		p.pwm2 = 7100;
	else if (p.pwm2<-7200)
		p.pwm2 = -7100;

	p.err_beforeLast2 = p.err_last2;
	p.err_last2 = p.err2;
	
	return p.pwm2;
}

int PID3(int Encoder3, int Target3)
{

	p.err3 = Encoder3 - Target3;
	p.pwm3 += kp3*(p.err3 - p.err_last3) + ki3*p.err3 + kd3*(p.err3 - 2 * p.err_last3 + p.err_beforeLast3);

	if (p.pwm3>7200)
		p.pwm3 = 7100;
	else if (p.pwm3<-7200)
		p.pwm3 = -7100;

	p.err_beforeLast3 = p.err_last3;
	p.err_last3 = p.err3;
	
	return p.pwm3;
}
int PID4(int Encoder4, int Target4)
{
		p.err4 = Encoder4 - Target4;
	p.pwm4 += kp4*(p.err4 - p.err_last4) + ki4*p.err4 + kd4*(p.err4 - 2 * p.err_last4 + p.err_beforeLast4);

	if (p.pwm4>7200)
		p.pwm4 = 7100;
	else if (p.pwm4<-7200)
		p.pwm4 = -7100;

	p.err_beforeLast4 = p.err_last4;
	p.err_last4 = p.err4;
	
	return p.pwm4;
}
