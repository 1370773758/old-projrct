#include "Delay.h"

void my_delay_ms(u32 ms)
{//对于stm32f1系列 72mhz大致是1ms
		u16 i = 0;
		while(ms--)
		{
			i = 4050;
			while(i--);
		};
}
void my_delay_us(u32 us)
{//对于stm32f1系列 72mhz大致是1us
		u16 i = 0;
		while(us--)
		{
			i = 2;
			while(i--);
		}
}

