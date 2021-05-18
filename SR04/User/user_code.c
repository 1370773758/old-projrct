#include "user_code.h"

void Init(void)
{

	TIM3_CounterMode();
	SR04_Cfg();
	
	USART1_QuickInit();			
  
	
}
