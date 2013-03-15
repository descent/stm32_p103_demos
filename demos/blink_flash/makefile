CFLAGS=-Wl,-T../main.ld -nostartfiles -fno-common -O0 -g -mcpu=cortex-m3 -mthumb
MYCFLAGS=-Wl,-T./stm32.ld -nostartfiles -fno-common -O0 -g -mcpu=cortex-m3 -mthumb

INC=-I./ -I/home/descent/my-git/jserv-course/stm32_p103_demos/libraries/CMSIS/CM3/CoreSupport -I/home/descent/my-git/jserv-course/stm32_p103_demos/libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I/home/descent/my-git/jserv-course/stm32_p103_demos/libraries/STM32F10x_StdPeriph_Driver/inc -I../common 

LIBFILES=/home/descent/my-git/jserv-course/stm32_p103_demos/libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s /home/descent/my-git/jserv-course/stm32_p103_demos/libraries/CMSIS/CM3/CoreSupport/core_cm3.c /home/descent/my-git/jserv-course/stm32_p103_demos/libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c ../common/stm32_p103.c /home/descent/my-git/jserv-course/stm32_p103_demos/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c /home/descent/my-git/jserv-course/stm32_p103_demos/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c /home/descent/my-git/jserv-course/stm32_p103_demos/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c /home/descent/my-git/jserv-course/stm32_p103_demos/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c /home/descent/my-git/jserv-course/stm32_p103_demos/libraries/STM32F10x_StdPeriph_Driver/src/misc.c 

main.bin: main.elf
	arm-none-eabi-objcopy -Obinary $< $@

main.elf: main.c
	arm-none-eabi-gcc $(CFLAGS) $(INC) -o $@ $< $(LIBFILES)

mymain.bin: mymain.elf
	arm-none-eabi-objcopy -Obinary $< $@

mymain.elf: mymain.c
	arm-none-eabi-gcc $(MYCFLAGS) $(INC) -o $@ $< 

#arm-none-eabi-objcopy -Obinary demos/blink_flash/main.elf demos/blink_flash/main.bin

#arm-none-eabi-objdump -S demos/blink_flash/main.elf > demos/blink_flash/main.list


#../qemu_stm32/arm-softmmu/qemu-system-arm -M stm32-p103 -kernel demos/blink_flash/main.bin
#/home/descent/my-git/jserv-course/qemu_stm32/arm-softmmu/qemu-system-arm -M stm32-p103 -kernel main.bin

clean:
	rm -rf *.o *.elf
