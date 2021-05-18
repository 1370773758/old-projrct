/**
  ******************************************************************************
  * @file    main.c 
  * @author  Luu_yy
  * @version 
  * @date    
  * @brief  
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/

#include "user_code.h"

/**
  * @brief  Main program.
  * @param  None
  * @retval 主函数要尽量的看起来整洁
  */
	

int main(void)
{
	Init();
	
	while(1)
	{
//		SysTick_Delay_Us(10);
		GPIO_SetBits(GPIOB,GPIO_Pin_0);
		SysTick_Delay_Us(40);
	 GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		my_delay_ms(60);
	if(Distance>0)
		{
			printf("Distance:%f cm\r\n",Distance);
		}
	}
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
