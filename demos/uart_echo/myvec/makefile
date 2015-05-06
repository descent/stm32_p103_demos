CFLAGS=-g
MYCFLAGS=-fno-common -O0 -g -mcpu=cortex-m3 -mthumb -I../ -I./ -I../../../libraries/CMSIS/CM3/CoreSupport -I../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../../../libraries/STM32F10x_StdPeriph_Driver/inc -I../../../demos/common -mfloat-abi=soft -DP103
MYCXXFLAGS = -fno-exceptions -fno-rtti -ffreestanding -nostdlib -nodefaultlibs
LD_FLAGS=-Wl,-T./stm32.ld -nostartfiles

OTHER_OBJS = ../../../libraries/CMSIS/CM3/CoreSupport/core_cm3.c ../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c ../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s ../../../demos/common/stm32_p103.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/misc.c

CXX=arm-none-eabi-g++
myvec.bin: myvec.elf
	arm-none-eabi-objcopy -Obinary $< $@

myvec.elf: myvec.o mem.o k_stdio.o vec.o
	arm-none-eabi-g++ $(MYCFLAGS)  -Wl,-Tmain.ld -nostartfiles $(CFLAGS) -I../../demos/uart_echo/ -o $@ $^ $(OTHER_OBJS) -lgcc

vec.o: vec.cpp
	$(CXX) $(MYCFLAGS) -c $<

mem.o: mem.cpp  
	$(CXX) $(MYCFLAGS) $(MYCXXFLAGS) -c $<
myvec.o: myvec.cpp
	$(CXX) $(MYCFLAGS) $(MYCXXFLAGS) -c $<

k_stdio.o: k_stdio.cpp
	$(CXX) $(MYCFLAGS) $(MYCXXFLAGS) -c $<

clean:
	rm -rf *.o *.elf *.bin *.dpp *.dpp.* 
distclean:
	rm -rf mem.cpp mem.h k_stdio.h k_stdio.cpp
	find . -type l -exec rm -f {} \; 
