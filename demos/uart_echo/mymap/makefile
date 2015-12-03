CXXFLAGS += $(MYCXXFLAGS) $(CFLAGS)

CFLAGS=-g
MYCFLAGS=-fno-common -O0 -g -mcpu=cortex-m3 -mthumb -I../ -I./ -I../../../libraries/CMSIS/CM3/CoreSupport -I../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../../../libraries/STM32F10x_StdPeriph_Driver/inc -I../../../demos/common -mfloat-abi=soft -DP103
MYCXXFLAGS = -fno-exceptions -fno-rtti -ffreestanding -nostdlib -nodefaultlibs
LD_FLAGS=-Wl,-T./stm32.ld -nostartfiles

OTHER_OBJS = ../../../libraries/CMSIS/CM3/CoreSupport/core_cm3.c ../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c ../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s ../../../demos/common/stm32_p103.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/misc.c

CXX=arm-none-eabi-g++

all: mymain.bin

mymain.elf: mymain.o bst.o k_stdio.o mem.o
	arm-none-eabi-g++ $(MYCFLAGS) $(MYCXXFLAGS) -Wl,-Tmain.ld -nostartfiles $(CFLAGS) -I../../demos/uart_echo/ -o $@ $(OTHER_OBJS) $^ -lgcc

mymain.o: mymain.cpp bst.h
	arm-none-eabi-g++ $(MYCFLAGS) $(MYCXXFLAGS) -Wl,-Tmain.ld -nostartfiles $(CFLAGS) -I../../demos/uart_echo/ -c $<

k_stdio.o: k_stdio.cpp k_stdio.h
	arm-none-eabi-g++ $(MYCFLAGS) $(MYCXXFLAGS) -Wl,-Tmain.ld -nostartfiles $(CFLAGS) -I../../demos/uart_echo/ -c $<

bst.o: bst.cpp bst.h
	arm-none-eabi-g++ $(MYCFLAGS) $(MYCXXFLAGS) -Wl,-Tmain.ld -nostartfiles $(CFLAGS) -I../../demos/uart_echo/ -c $<

mem.o: mem.cpp mem.h
	arm-none-eabi-g++ -DSTM32 $(MYCFLAGS) $(MYCXXFLAGS) -Wl,-Tmain.ld -nostartfiles $(CFLAGS) -I../../demos/uart_echo/ -c $<

mymain.bin: mymain.elf
	arm-none-eabi-objcopy -Obinary $< $@

#arm-none-eabi-objdump -S demos/uart_echo/main.elf > demos/uart_echo/main.list

clean:
	rm -rf *.o *.elf *.bin *.dpp *.dpp.*
distclean:
	find . -type l -exec rm -f {} \;