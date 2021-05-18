#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "user_common.h"

void USART1_QuickInit(void);




void USART_sendChar(USART_TypeDef* USARTx, char ch); 
int fputc(int ch, FILE *f);
int fgetc(FILE *f);

#endif /* __BSP_USART_H */
