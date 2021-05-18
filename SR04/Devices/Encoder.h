#ifndef __ENCODER_H
#define __ENCODER_H

#include "stm32f10x.h"

void Encoder_TIM4_Mode_Config(uint32_t psc1,uint32_t arr1);
void Encoder_TIM2_Mode_Config(uint32_t psc1,uint32_t arr1);
void Encoder_TIM3_Mode_Config(uint32_t psc1,uint32_t arr1);
void Encoder_TIM5_Mode_Config(uint32_t psc1,uint32_t arr1);
int Read_Encoder(u8 TIMX);
void GPIO_AFIODeInit(void);

#endif  /*__ENCODER_H*/
