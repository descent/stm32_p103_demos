#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_p103.h"
#include "k_stdio.h"
#include "cstring.h"

using namespace DS;



uint8_t get_byte()
{
  while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET);

  return (USART_ReceiveData(USART2) & 0x7F);
}

void vec_test();
void vec_test_eh();


extern "C"
{
  int main(void)
  {

    init_rs232();
    USART_Cmd(USART2, ENABLE);
    vec_test();

    return 0;
  }
}
