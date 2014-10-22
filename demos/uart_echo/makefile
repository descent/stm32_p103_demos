all: main.bin mymain.bin

main.bin: main.elf
	arm-none-eabi-objcopy -Obinary $< $@

main.elf: main.c
	arm-none-eabi-gcc -Wl,-T../../demos/main.ld -nostartfiles -I./ -I../..//libraries/CMSIS/CM3/CoreSupport -I../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../..//libraries/STM32F10x_StdPeriph_Driver/inc -I../../demos/common -fno-common -O0 -g -mcpu=cortex-m3 -mthumb  -I../../demos/uart_echo/ -o $@ ../..//libraries/CMSIS/CM3/CoreSupport/core_cm3.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s ../../demos/common/stm32_p103.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/misc.c main.c

mymain.elf: mymain.cpp
	arm-none-eabi-g++ -fno-exceptions -fno-rtti -Wl,-T../../demos/main.ld -nostartfiles -I./ -I../..//libraries/CMSIS/CM3/CoreSupport -I../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../..//libraries/STM32F10x_StdPeriph_Driver/inc -I../../demos/common -fno-common -O0 -g -mcpu=cortex-m3 -mthumb  -I../../demos/uart_echo/ -o $@ ../..//libraries/CMSIS/CM3/CoreSupport/core_cm3.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c ../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s ../../demos/common/stm32_p103.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c ../..//libraries/STM32F10x_StdPeriph_Driver/src/misc.c $<

mymain.bin: mymain.elf
	arm-none-eabi-objcopy -Obinary $< $@

#arm-none-eabi-objcopy -Obinary demos/uart_echo/main.elf demos/uart_echo/main.bin

#arm-none-eabi-objdump -S demos/uart_echo/main.elf > demos/uart_echo/main.list

clean:
	rm -rf *.o *.elf *.bin
