#include "control.h"

int Motor1,Motor2,Motor3,Motor4;
int Encoder1,Encoder2,Encoder3,Encoder4;
int Target1,Target2,Target3,Target4;
int Target_velocity=0 ;     //目标速度
int velocity2 ;     //目标速度
int velocity3 ;     //目标速度
int velocity4 ;     //目标速度

void Set_Pwm(int motor)
{
	if(motor>0)
	{
		AIN_B4_ON;
		AIN_B5_OFF;
	}
	else
	{
		AIN_B4_OFF;
		AIN_B5_ON;
	}
	TIM_SetCompare1(TIM8,motor_abs(motor));
}

void Set_Pwm2(int motor)
{
	if(motor>0)
	{
		AIN_D1_ON;
		AIN_D2_OFF;
	}
	else
	{
		AIN_D1_OFF;
		AIN_D2_ON;
	}
	TIM_SetCompare2(TIM8,motor_abs(motor));
}

void Set_Pwm3(int motor)
{
	if(motor>0)
	{
		AIN_A4_ON;
		AIN_A5_OFF;
	}
	if(motor<0)
	{
		AIN_A4_OFF;
		AIN_A5_ON;
	}
	TIM8 ->CCR3 = motor_abs(motor);
}

void Set_Pwm4(int motor)
{
	if(motor>0)
	{
		AIN_A4_ON;
		AIN_A5_OFF;
	}
	else
	{
		AIN_A4_OFF;
		AIN_A5_ON;
	}
	TIM_SetCompare4(TIM8,motor_abs(motor));
}


int motor_abs(int a)
{
	int tump;
	if(a<0) tump = -a;
	else tump = a;
	return tump;
}
