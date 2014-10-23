CXX = arm-none-eabi-g++

CFLAGS = -fno-common -O0 -g -mcpu=cortex-m3 -mthumb -ffreestanding  -nostdlib -nodefaultlibs 
CXXFLAGS = -fno-exceptions -fno-rtti

OTHER_OBJS = ../..//libraries/CMSIS/CM3/CoreSupport/core_cm3.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s ../../demos/common/stm32_p103.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/misc.c

all: main.bin mymain.bin

main.bin: main.elf
	arm-none-eabi-objcopy -Obinary $< $@

main.elf: main.c
	arm-none-eabi-gcc -Wl,-Tmain.ld -nostartfiles -I./ -I../..//libraries/CMSIS/CM3/CoreSupport -I../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../..//libraries/STM32F10x_StdPeriph_Driver/inc -I../../demos/common $(CFLAGS)  -I../../demos/uart_echo/ -o $@ $(OTHER_OBJS) $^

mymain.elf: mymain.cpp token_container.o s_eval.o cell.o
	arm-none-eabi-g++ $(CFLAGS) $(CXXFLAGS) -Wl,-Tmain.ld -nostartfiles -I./ -I../..//libraries/CMSIS/CM3/CoreSupport -I../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../..//libraries/STM32F10x_StdPeriph_Driver/inc -I../../demos/common $(CFLAGS) -I../../demos/uart_echo/ -o $@ $(OTHER_OBJS) $^

mymain.bin: mymain.elf
	arm-none-eabi-objcopy -Obinary $< $@

token_container.o: token_container.cpp token_container.h
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $<

s_eval.o: s_eval.cpp s_eval.h
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $<

cell.o: cell.cpp cell.h
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $<

#arm-none-eabi-objcopy -Obinary demos/uart_echo/main.elf demos/uart_echo/main.bin

#arm-none-eabi-objdump -S demos/uart_echo/main.elf > demos/uart_echo/main.list

clean:
	rm -rf *.o *.elf *.bin
