include rule.mk

# only for -finstrument-functions
#CFLAGS = -fno-common -O0 -g -mcpu=cortex-m3 -mthumb -ffreestanding  -nostdlib -nodefaultlibs -I./ -I../..//libraries/CMSIS/CM3/CoreSupport -I../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../..//libraries/STM32F10x_StdPeriph_Driver/inc -I../../demos/common -mfloat-abi=soft -DP103 -DSP_STATUS -finstrument-functions


CXXFLAGS += $(MYCXXFLAGS) $(CFLAGS)

# make STACK_REG=1 will go -finstrument-functions
ifndef STACK_REG
CFLAGS += $(MYCFLAGS)
else
# only for -finstrument-functions
CFLAGS += $(MYCFLAGS) -DSP_STATUS -finstrument-functions
endif


OTHER_OBJS = ../..//libraries/CMSIS/CM3/CoreSupport/core_cm3.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s ../../demos/common/stm32_p103.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/misc.c

all: main.bin mymain.bin

main.bin: main.elf
	arm-none-eabi-objcopy -Obinary $< $@

main.elf: main.c
	arm-none-eabi-gcc -Wl,-Tmain.ld -nostartfiles $(CFLAGS)  -I../../demos/uart_echo/ -o $@ $(OTHER_OBJS) $^

mymain.elf: mymain.o token_container.o s_eval.o cell.o k_stdio.o gdeque.o cstring.o
	arm-none-eabi-g++ $(CFLAGS) $(CXXFLAGS) -Wl,-Tmain.ld -nostartfiles $(CFLAGS) -I../../demos/uart_echo/ -o $@ $(OTHER_OBJS) $^ -lgcc

mymain.bin: mymain.elf
	arm-none-eabi-objcopy -Obinary $< $@

#arm-none-eabi-objdump -S demos/uart_echo/main.elf > demos/uart_echo/main.list

sources = cell.cpp  k_stdio.cpp  mymain.cpp  s_eval.cpp  token_container.cpp gdeque.cpp cstring.cpp

include $(sources:.cpp=.dpp)


clean:
	rm -rf *.o *.elf *.bin *.dpp *.dpp.*
distclean:
	find . -type l -exec rm -f {} \;
