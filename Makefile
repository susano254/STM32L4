projectName = $(shell basename $(shell pwd))
TOOLCHAIN = /home/mahmoud/arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi/bin

# cpu
CPU = -mcpu=cortex-m4

# fpu
FPU = -mfpu=fpv4-sp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI) 

all: compile link upload

build:	compile link

compile: src/$(projectName).c 
	$(TOOLCHAIN)/arm-none-eabi-gcc -g -c $(MCU) src/main.c -o Build/main.o -I ../include/
	$(TOOLCHAIN)/arm-none-eabi-gcc -g -c $(MCU) src/$(projectName).c -o ../drivers/$(projectName).o -I ../include/

assemble:
	$(TOOLCHAIN)/arm-none-eabi-as -g -mcpu=cortex-m4 -mthumb ../startup/startup_stm32l432xx.s -o Build/startup_stm32l432xx.o

link:	compile	assemble
	$(TOOLCHAIN)/arm-none-eabi-gcc $(MCU) --specs=nano.specs --specs=nosys.specs Build/*.o ../drivers/*.o -o Build/$(projectName).elf -T ../linker/STM32L432KCUx_FLASH.ld  

upload:	link
	openocd -f interface/stlink.cfg -f target/stm32l4x.cfg -c "program Build/$(projectName).elf verify reset exit"

debug:
	openocd -f interface/stlink.cfg -f target/stm32l4x.cfg
