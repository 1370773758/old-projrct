#include "Delay.h"

void my_delay_ms(u32 ms)
{//����stm32f1ϵ�� 72mhz������1ms
		u16 i = 0;
		while(ms--)
		{
			i = 4050;
			while(i--);
		};
}
void my_delay_us(u32 us)
{//����stm32f1ϵ�� 72mhz������1us
		u16 i = 0;
		while(us--)
		{
			i = 2;
			while(i--);
		}
}

