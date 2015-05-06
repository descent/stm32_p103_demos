#!/bin/sh
qemu_stm32/arm-softmmu/qemu-system-arm -display sdl -M stm32-p103 -kernel myvec.bin -nographic
