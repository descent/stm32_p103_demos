CXX = arm-none-eabi-g++

CFLAGS = -fno-common -O0 -g -mcpu=cortex-m3 -mthumb -ffreestanding  -nostdlib -nodefaultlibs -I./ -I../..//libraries/CMSIS/CM3/CoreSupport -I../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../..//libraries/STM32F10x_StdPeriph_Driver/inc -I../../demos/common -mfloat-abi=softfp
CXXFLAGS = -fno-exceptions -fno-rtti

OTHER_OBJS = ../..//libraries/CMSIS/CM3/CoreSupport/core_cm3.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s ../../demos/common/stm32_p103.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/misc.c

all: main.bin mymain.bin

main.bin: main.elf
	arm-none-eabi-objcopy -Obinary $< $@

main.elf: main.c
	arm-none-eabi-gcc -Wl,-Tmain.ld -nostartfiles $(CFLAGS)  -I../../demos/uart_echo/ -o $@ $(OTHER_OBJS) $^

mymain.elf: mymain.o token_container.o s_eval.o cell.o k_stdio.o mydeque.o
	arm-none-eabi-g++ $(CFLAGS) $(CXXFLAGS) -Wl,-Tmain.ld -nostartfiles $(CFLAGS) -I../../demos/uart_echo/ -o $@ $(OTHER_OBJS) $^

mymain.bin: mymain.elf
	arm-none-eabi-objcopy -Obinary $< $@
# arm-none-eabi-g++ -fno-exceptions -fno-rtti -fno-common -O0 -g -mcpu=cortex-m3 -mthumb -ffreestanding  -nostdlib -nodefaultlibs -I./ -I../..//libraries/CMSIS/CM3/CoreSupport -I../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../..//libraries/STM32F10x_StdPeriph_Driver/inc -I../../demos/common -MM token_container.cpp

mymain.o: mymain.cpp stm32f10x.h \
 ../..//libraries/CMSIS/CM3/CoreSupport/core_cm3.h \
  ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.h \
   type.h stm32f10x_conf.h \
    ../..//libraries/STM32F10x_StdPeriph_Driver/inc/stm32f10x_usart.h \
     stm32f10x.h ../../demos/common/stm32_p103.h k_stdio.h s_eval.h cell.h \
      k_string.h token_container.h
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $<


token_container.o: token_container.cpp token_container.h k_string.h type.h k_stdio.h
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $<
token_container.h:
	ln -s ~/git/simple_scheme/token_container.h .
token_container.cpp:
	ln -s ~/git/simple_scheme/token_container.cpp .
s_eval.h:
	ln -s ~/git/simple_scheme/s_eval.h .
s_eval.cpp:
	ln -s ~/git/simple_scheme/s_eval.cpp  .
cell.h:
	ln -s ~/git/simple_scheme/cell.h .
cell.cpp:
	ln -s ~/git/simple_scheme/cell.cpp .

s_eval.o: s_eval.cpp k_string.h type.h s_eval.h cell.h k_stdio.h token_container.h
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $<

cell.o: cell.cpp cell.h k_string.h type.h k_stdio.h
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $<

k_stdio.o: k_stdio.cpp k_stdio.h
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $<

mydeque.o: mydeque.cpp mydeque.h 
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $<

#arm-none-eabi-objcopy -Obinary demos/uart_echo/main.elf demos/uart_echo/main.bin

#arm-none-eabi-objdump -S demos/uart_echo/main.elf > demos/uart_echo/main.list

clean:
	rm -rf *.o *.elf *.bin 
distclean:
	find . -type l -exec rm -f {} \;
