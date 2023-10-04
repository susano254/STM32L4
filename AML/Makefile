projectName = $(shell basename $(shell pwd))
TOOLCHAIN =# /home/mahmoud/arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi/bin

# cpu
CPU = -mcpu=cortex-m4

# fpu
FPU = -mfpu=fpv4-sp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI) 

#no exceptions , no runtime type information (no virtual pointers table) each function linked individualy
#at the cost of increase linker time
CC_OPTIONS = -fno-exceptions -fno-rtti -ffunction-sections 
#no start files from the system explicitly use the start files in one of the .o files
LD_OPTIONS = -nostartfiles --specs=nano.specs --specs=nosys.specs
#link math library
LIBS = -lm

all: compile link 

build:	compile link

compile: #src/$(projectName).cpp
	$(TOOLCHAIN)arm-none-eabi-g++ -g -c $(MCU) $(CC_OPTIONS) src/main.cpp -o Build/main.o -I ../include/ -I ../include/AML
#	$(TOOLCHAIN)/arm-none-eabi-g++ -g -c $(MCU) $(CC_OPTIONS) src/$(projectName).cpp -o ../drivers/$(projectName).o -I ../include/ -I ../include/AML
	$(TOOLCHAIN)arm-none-eabi-g++ -g -c $(MCU) $(CC_OPTIONS) src/Vector3.cpp -o ../drivers/Vector3.o -I ../include/ -I ../include/AML
	$(TOOLCHAIN)arm-none-eabi-g++ -g -c $(MCU) $(CC_OPTIONS) src/Matrix33.cpp -o ../drivers/Matrix33.o -I ../include/ -I ../include/AML
	$(TOOLCHAIN)arm-none-eabi-g++ -g -c $(MCU) $(CC_OPTIONS) src/DCM.cpp -o ../drivers/DCM.o -I ../include/ -I ../include/AML
	$(TOOLCHAIN)arm-none-eabi-g++ -g -c $(MCU) $(CC_OPTIONS) src/EulerAngles.cpp -o ../drivers/EulerAngles.o -I ../include/ -I ../include/AML
	$(TOOLCHAIN)arm-none-eabi-g++ -g -c $(MCU) $(CC_OPTIONS) src/Quaternion.cpp -o ../drivers/Quaternion.o -I ../include/ -I ../include/AML

assemble:
	$(TOOLCHAIN)arm-none-eabi-as -g -mcpu=cortex-m4 -mthumb ../startup/startup_stm32l432xx.s -o Build/startup_stm32l432xx.o

link:	compile	assemble
	$(TOOLCHAIN)arm-none-eabi-g++ $(MCU) $(LD_OPTIONS)  Build/*.o ../drivers/*.o -o Build/$(projectName).elf -T ../linker/STM32L432KCUx_FLASH.ld  $(LIBS)

upload:	link
	openocd -f interface/stlink.cfg -f target/stm32l4x.cfg -c "program Build/$(projectName).elf verify reset exit"

debug:
	openocd -f interface/stlink.cfg -f target/stm32l4x.cfg
