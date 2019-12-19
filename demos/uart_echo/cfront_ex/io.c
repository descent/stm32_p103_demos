#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_p103.h"

int printf(const char *format, ...)
{
}

void send_byte(uint8_t b)
{
    /* Send one byte */
    USART_SendData(USART2, b);

    /* Loop until USART2 DR register is empty */
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}

int puts(const char *s)
{
  const char *cp = s;
  while(*cp)
  {
    send_byte(*cp);
    ++cp;
  }
  return 0;
}


void init_rs232_wrap()
{
  init_rs232();
  USART_Cmd(USART2, ENABLE);
}
