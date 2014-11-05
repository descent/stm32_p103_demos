#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_p103.h"
#include "k_stdio.h"
#include "s_eval.h"

#if 0
void send_byte(uint8_t b)
{
    /* Send one byte */
    USART_SendData(USART2, b);

    /* Loop until USART2 DR register is empty */
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}
#endif

void abc(const char *str)
{
  myprint(str);
  getchar();
}

extern "C"
{
int main(void)
{
    init_rs232();
    USART_Cmd(USART2, ENABLE);
  mydeque.init();
  init_eval();
  Environment *global_env = get_env(0, "global");
  create_primitive_procedure(global_env);
  repl("simple scheme> ", global_env);
  return 0;

}
}
