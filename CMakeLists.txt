cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME project)
project(${PROJECT_NAME} C)

set(TOOLCHAIN /home/mahmoud/arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi/bin)

# cpu
set(CPU -mcpu=cortex-m4)

# fpu
set(FPU -mfpu=fpv4-sp-d16)

# float-abi
set(FLOAT-ABI -mfloat-abi=hard)

# mcu
set(MCU ${CPU} -mthumb ${FPU} ${FLOAT-ABI})

add_executable(${PROJECT_NAME}.elf src/main.c)
add_library(${PROJECT_NAME} ../drivers/project.c)

target_compile_options(${PROJECT_NAME}.elf PRIVATE ${MCU} -g)
target_compile_options(${PROJECT_NAME} PRIVATE ${MCU} -g)
target_compile_options(${PROJECT_NAME} PRIVATE ${MCU} -c -o ${PROJECT_BINARY_DIR}/src/main.o -I ${CMAKE_SOURCE_DIR}/include)
target_compile_options(${PROJECT_NAME} PRIVATE ${MCU} -c -o ${PROJECT_BINARY_DIR}/../drivers/project.o -I ${CMAKE_SOURCE_DIR}/include)

add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/Build/startup_stm32l432xx.o
  COMMAND ${TOOLCHAIN}/arm-none-eabi-as -g -mcpu=cortex-m4 -mthumb ${CMAKE_SOURCE_DIR}/startup/startup_stm32l432xx.s -o ${PROJECT_BINARY_DIR}/Build/startup_stm32l432xx.o
)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
  COMMAND ${TOOLCHAIN}/arm-none-eabi-gcc ${MCU} --specs=nano.specs --specs=nosys.specs $<TARGET_OBJECTS:${PROJECT_NAME}.elf> $<TARGET_OBJECTS:${PROJECT_NAME}> ${PROJECT_BINARY_DIR}/Build/startup_stm32l432xx.o -o ${PROJECT_BINARY_DIR}/Build/${PROJECT_NAME}.elf -T ${CMAKE_SOURCE_DIR}/linker/STM32L432KCUx_FLASH.ld -lm
)

add_custom_target(compile ALL
  DEPENDS ${PROJECT_BINARY_DIR}/src/main.o ${PROJECT_BINARY_DIR}/../drivers/project.o ${PROJECT_BINARY_DIR}/Build/startup_stm32l432xx.o
)

add_custom_target(link ALL
  DEPENDS ${PROJECT_BINARY_DIR}/Build/${PROJECT_NAME}.elf
)

add_custom_target(upload ALL
  DEPENDS link
  COMMAND openocd -f interface/stlink.cfg -f target/stm32l4x.cfg -c "program ${PROJECT_BINARY_DIR}/Build/${PROJECT_NAME}.elf verify reset exit"
)

add_custom_target(debug
  COMMAND openocd -f interface/stlink.cfg -f target/stm32l4x.cfg
)