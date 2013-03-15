#ifndef STM32_H
#define STM32_H
#if 0
#define GPIOB_CRL     (*(volatile unsigned long *)0x40010c00)
#define GPIOB_BSRR    (*(volatile unsigned long *)0x40010c10)
#define GPIOB_BRR     (*(volatile unsigned long *)0x40010c14)
#define RCC_APB2ENR   (*(volatile unsigned long *)0x40021018)
#endif

#define STACK_SIZE 64
extern unsigned long _etext;
extern unsigned long _data;
extern unsigned long _edata;
extern unsigned long _bss;
extern unsigned long _ebss;

void ResetISR(void)
{
  unsigned long *pulSrc, *pulDest;

  pulSrc = &_etext;
  for (pulDest = &_data; pulDest < &_edata;)
    *pulDest++ = *pulSrc++;
  for (pulDest = &_bss; pulDest < &_ebss;)
    *pulDest++ = 0;

  main();
}

typedef void (*pfnISR)(void);
__attribute__((section(".stackares")))
static unsigned long pulStack[STACK_SIZE];


__attribute__((section(".isr_vector")))
pfnISR VectorTable[]=
{
  (pfnISR)((unsigned long)pulStack+sizeof(pulStack)),
  ResetISR
};

#endif
