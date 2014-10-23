#include "k_stdio.h"
#include "k_string.h"

#if 0
#define USE_STDPERIPH_DRIVER
#include "stm32_p103.h"
#endif
#include "stm32f10x.h"

void send_byte(u8 b)
{
  /* Send one byte */
  USART_SendData(USART2, b);

  /* Loop until USART2 DR register is empty */
  while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}

void myprint(const char *str)
{
  const char *p = str;
  while(*p++)
    send_byte(*p);
}

int keep_char = -1;

int ungetch(int c)
{
  keep_char = c;
  return 0;
}

int getchar()
{
  if (keep_char != -1 )
    return keep_char;
  else
  {
    int b;
    while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET);
    b = (USART_ReceiveData(USART2) & 0x7F);
    send_byte(b);
  }
}
