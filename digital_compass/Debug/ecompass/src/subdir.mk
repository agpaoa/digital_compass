################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ecompass/src/cr_startup_lpc175x_6x.c \
../ecompass/src/ecompass.c \
../ecompass/src/main.c \
../ecompass/src/sysinit.c 

OBJS += \
./ecompass/src/cr_startup_lpc175x_6x.o \
./ecompass/src/ecompass.o \
./ecompass/src/main.o \
./ecompass/src/sysinit.o 

C_DEPS += \
./ecompass/src/cr_startup_lpc175x_6x.d \
./ecompass/src/ecompass.d \
./ecompass/src/main.d \
./ecompass/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
ecompass/src/%.o: ../ecompass/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -D__NEWLIB__ -I"C:\Users\Richie\Home\LPCXpresso\digital_compass\lpc_chip_175x_6x\inc" -I"C:\Users\Richie\Home\LPCXpresso\digital_compass\lpc_board_nxp_lpcxpresso_1769\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


