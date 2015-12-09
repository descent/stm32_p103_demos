#/home/descent/git/jserv-course/qemu_stm32/arm-softmmu/qemu-system-arm -display sdl -M stm32-p103 -kernel mymain.bin
#/home/descent/git/jserv-course/qemu_stm32/arm-softmmu/qemu-system-arm -display sdl -M stm32-p103 -kernel mymain.bin -S -gdb tcp::1234


ref: https://draskodraskovic.wordpress.com/2012/05/26/running-qemu-in-nographic-mode/
To see the help use <Ctrl-a h> or <Ctrl-a ?> :

VersatilePB #

C-a x exit emulator

C-a h print this help
C-a s save disk data back to file (if -snapshot)
C-a t toggle console timestamps
C-a b send break (magic sysrq)
C-a c switch between console and monitor
C-a C-a sends C-a

<Ctrl-a x> toggles between qemu monitor (internal to qemu) and console in which u-boot is run :

/media/2/qemu_stm32/arm-softmmu/qemu-system-arm -display sdl -M stm32-p103 -kernel mymain.bin -display sdl
#/media/2/qemu_stm32/arm-softmmu/qemu-system-arm -display sdl -M stm32-p103 -kernel mymain.bin  -S -gdb tcp::1234


 #/media/2/qemu_stm32/arm-softmmu/qemu-system-arm -M stm32-p103 -kernel mymain.bin  -nographic
 #/media/2/qemu_stm32/arm-softmmu/qemu-system-arm -M stm32-p103 -kernel mymain.bin  -curses


