#ifndef BSP_GPIO_H
#define BSP_GPIO_H

#include "user_common.h"

#define AIN_A4_ON				GPIOA->BSRR = GPIO_Pin_4
#define AIN_A4_OFF			GPIOA->BRR = GPIO_Pin_4
#define AIN_A5_ON				GPIOA->BSRR = GPIO_Pin_5
#define AIN_A5_OFF			GPIOA->BRR = GPIO_Pin_5

#define AIN_B4_ON				GPIOB->BSRR = GPIO_Pin_4
#define AIN_B4_OFF			GPIOB->BRR = GPIO_Pin_4
#define AIN_B5_ON				GPIOB->BSRR = GPIO_Pin_5
#define AIN_B5_OFF			GPIOB->BRR = GPIO_Pin_5

#define AIN_C2_ON				GPIOC->BSRR = GPIO_Pin_2
#define AIN_C2_OFF			GPIOC->BRR = GPIO_Pin_2
#define AIN_C3_ON				GPIOC->BSRR = GPIO_Pin_3
#define AIN_C3_OFF			GPIOC->BRR = GPIO_Pin_3

#define AIN_D1_ON				GPIOD->BSRR = GPIO_Pin_1
#define AIN_D1_OFF			GPIOD->BRR = GPIO_Pin_1
#define AIN_D2_ON				GPIOD->BSRR = GPIO_Pin_2
#define AIN_D2_OFF			GPIOD->BRR = GPIO_Pin_2

void AIN_GPIO(void);
	
#endif  
