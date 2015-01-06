#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_p103.h"
#include "k_stdio.h"
#include "s_eval.h"
#include "gdeque.h"
#include "cstring.h"

using namespace DS;

#if 0
void send_byte(uint8_t b)
{
    /* Send one byte */
    USART_SendData(USART2, b);

    /* Loop until USART2 DR register is empty */
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}
#endif

uint8_t get_byte()
{
  while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET);

  return (USART_ReceiveData(USART2) & 0x7F);
}

u8 buf[20];


bool is_up(const char *buf)
{
  if (buf[0] == 27 && buf[1] == '[' && buf[2] == 'A')
    return true;
  else
    return false;
}

bool is_down(const char *buf)
{
  if (buf[0] == 27 && buf[1] == '[' && buf[2] == 'B')
    return true;
  else
    return false;
}

// Deque<DS::CString> deque;
//DS::Deque<int, 128> line_buf;


u32 get_stack_reg()
{
  u32 tmp_sp;

  __asm__ (
            "mov %0, sp\n"
            : "=r"(tmp_sp)
            :
          );
  return tmp_sp;
}
extern "C"
{
#ifdef SP_STATUS
u32 sp_val=0xffffffff;
// ref: http://blog.linux.org.tw/~jserv/archives/001870.html
__attribute__((__no_instrument_function__))
void __cyg_profile_func_enter(void *this_func, void *call_site)
{

}

__attribute__((__no_instrument_function__))
void __cyg_profile_func_exit(void *this_func, void *call_site)
{
  u32 tmp_sp; 

   __asm__ (
             "mov %0, sp\n"
             : "=r"(tmp_sp)
             :
           );
  if (tmp_sp < sp_val)
    sp_val = tmp_sp;
}

#endif

int main(void)
{
  init_rs232();
  USART_Cmd(USART2, ENABLE);

  DS::Deque<int, 128> test_buf;

  test_buf.init();

#if 0


  u8 ch;
  int i=0;
  char input_str[20];
  char *sb=0;
  DS::CString ps;
  int index = 0;
  while(1)
  {
    sb = gets(input_str, 20);
    if (is_up(sb))
    {
      ++index;
      if (deque.back(index, ps) == true)
      {
        myprint(ps.c_str());
      }
      else
        --index;
    }
    else if (is_down(sb))
         {
            --index;
            if (deque.back(index, ps) == true)
            {
              myprint(ps.c_str());
            }
            else
            {
              ++index;
            }

         }
         else
         {
           myprint(sb);
           myprint("\r\n");
           ps = sb;
           deque.push_back(ps);
         }


  }

    float f=1.5;
    myprint_float(f);
    myprint("\r\nabc");
    while(1);
  int b;
  while(1)
  {
    b=read_char();
  }

#else
  init_eval();
  //deque.init();
  mydeque.init();
  //line_buf.init();
  Environment *global_env = get_env(0, "global");
  create_primitive_procedure(global_env);
  non_os_repl("simple scheme> ", global_env);
#endif
  return 0;

}
}
