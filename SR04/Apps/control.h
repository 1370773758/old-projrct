#ifndef __CONTROL_H
#define __CONTROL_H

#include "user_common.h"

extern int Encoder1,Encoder2,Encoder3,Encoder4;
extern int Target_velocity,velocity2,velocity3,velocity4;
extern int Target1,Target2,Target3,Target4;
extern int Motor1,Motor2,Motor3,Motor4;
//extern incrementalpid_t;

//λ������,ʵ��51���Ƶ�GPIO���ƹ���
//����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).
//IO�ڲ����궨��

void  Set_Pwm(int motor);
void  Set_Pwm2(int motor);
void  Set_Pwm3(int motor);
void  Set_Pwm4(int motor);

int motor_abs(int a);

#endif    /*__CONTROL_H*/
