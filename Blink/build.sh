arm-none-eabi-gcc -g -c -mcpu=cortex-m4 -mthumb  src/Blink.c -o Build/Blink.o -I include/
arm-none-eabi-as -g -mcpu=cortex-m4 -mthumb src/startup_stm32l432xx.s -o Build/startup_stm32l432xx.o
arm-none-eabi-ld Build/*.o -o Build/Blink.elf -T src/STM32L432KCUx_FLASH.ld
openocd -f interface/stlink.cfg -f target/stm32l4x.cfg -c "program Build/Blink.elf verify reset exit"