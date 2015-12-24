CFLAGS=-g
MYCFLAGS=-fno-common -O0 -g -mcpu=cortex-m3 -mthumb -ffreestanding  -nostdlib -nodefaultlibs -I./ -I../..//libraries/CMSIS/CM3/CoreSupport -I../..//libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x -I../..//libraries/STM32F10x_StdPeriph_Driver/inc -I../../demos/common -mfloat-abi=soft -DP103  -Iinc
MYCXXFLAGS = -fno-exceptions -fno-rtti -std=c++11
LD_FLAGS=-Wl,-T./stm32.ld -nostartfiles
CXX=arm-none-eabi-g++
%.dpp: %.cpp
	set -e; rm -f $@ ; $(CXX) -std=c++11 -MM $(MYCFLAGS) $< > $@.$$$$ ; sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@ ; rm -f $@.$$$$

