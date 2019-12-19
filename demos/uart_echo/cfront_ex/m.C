#include "t.h"

extern "C"
{
  int atexit(void (*function)(void))
  {
    return 0;
  }

  void *malloc(int size)
  {
    static char m[100];
    return m;
  }

  void free(void *ptr)
  {
  }

  int puts(const char *s);
  void init_rs232_wrap();
}


int main(void)
{
  int b;

  init_rs232_wrap();

  D1 d1;
  D2 d2;

    while(1);
#if 0
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
}

#if 0
int main(int argc, char *argv[])
{
  D1 d1;
  D2 d2;

  printf("d1.num: %d\n", d1.get_num());
  printf("d2.num: %d\n", d1.get_num());
  printf("d1.a: %d\n", d1.get_a());
  printf("d2.b: %d\n", d2.get_b());
  
  return 0;
}
#endif
