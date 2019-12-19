#!/bin/sh
set -x

arm-none-eabi-gcc -Wl,-Tmain.ld -nostartfiles -g -fno-common -O0 -g -mcpu=cortex-m3 -mthumb -ffreestanding  -nostdlib -nodefaultlibs -I./ -I../../../libraries/CMSIS/CM3/CoreSupport -I../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../../../libraries/STM32F10x_StdPeriph_Driver/inc -I../../../demos/common -mfloat-abi=soft -DP103  -Iinc  -I../../../demos/uart_echo/ -E t.C > t.i

./cfront +a1 +L +ft.C < t.i > t..c

arm-none-eabi-gcc -Wl,-Tmain.ld -nostartfiles -g -fno-common -O0 -g -mcpu=cortex-m3 -mthumb -ffreestanding  -nostdlib -nodefaultlibs -I./ -I../../../libraries/CMSIS/CM3/CoreSupport -I../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../../../libraries/STM32F10x_StdPeriph_Driver/inc -I../../demos/common -mfloat-abi=soft -DP103  -Iinc  -I../../demos/uart_echo/ -E m.C > m.i

./cfront +a1 +L +fm.C < m.i > m..c

arm-none-eabi-gcc -Wl,-Tmain.ld -nostartfiles -g -fno-common -O0 -g -mcpu=cortex-m3 -mthumb -ffreestanding  -nostdlib -nodefaultlibs -I. -I../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/ -I../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/ -I./ -I../../../libraries/CMSIS/CM3/CoreSupport -I../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../../../libraries/STM32F10x_StdPeriph_Driver/inc -I../../../demos/common -mfloat-abi=soft -DP103  -Iinc  -I../../demos/uart_echo/ -o m.elf ../../../libraries/CMSIS/CM3/CoreSupport/core_cm3.c ../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c ../../../libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s ../../../demos/common/stm32_p103.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c ../../../libraries/STM32F10x_StdPeriph_Driver/src/misc.c m..c  t..c io.c ./libC.a
