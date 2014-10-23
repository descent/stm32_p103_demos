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

extern "C"
{
int main(void)
{
    init_rs232();
    USART_Cmd(USART2, ENABLE);
#if 0
    uint8_t b;


    while(1) {
        /* Loop until the USART2 has received a byte. */
        while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET);

        /* Capture the received byte and print it out. */
        b = (USART_ReceiveData(USART2) & 0x7F);
        send_byte('G');
        send_byte('o');
        send_byte('t');
        send_byte(':');
        send_byte(b);
        send_byte('\n');
    }
#endif
  init_eval();
  Environment *global_env = get_env(0, "global");
  create_primitive_procedure(global_env);
#if 0
  while(1)
  {
    myprint("simple scheme> ");
    getchar();
  }
#else
  repl("simple scheme> ", global_env);
#endif
  return 0;

}
}
