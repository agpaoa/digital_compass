################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/cr_startup_lpc175x_6x.c \
../example/src/ecompass.c \
../example/src/main.c \
../example/src/sysinit.c 

OBJS += \
./example/src/cr_startup_lpc175x_6x.o \
./example/src/ecompass.o \
./example/src/main.o \
./example/src/sysinit.o 

C_DEPS += \
./example/src/cr_startup_lpc175x_6x.d \
./example/src/ecompass.d \
./example/src/main.d \
./example/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -D__NEWLIB__ -I"C:\Users\Richie\Documents\LPCXpresso_8.0.0_526\workspace\lpc_chip_175x_6x\inc" -I"C:\Users\Richie\Documents\LPCXpresso_8.0.0_526\workspace\lpc_board_nxp_lpcxpresso_1769\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

