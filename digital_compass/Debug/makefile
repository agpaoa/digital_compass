################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ecompass/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: digital_compass.axf

# Tool invocations
digital_compass.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Richie\Home\LPCXpresso\digital_compass\lpc_chip_175x_6x\Debug" -L"C:\Users\Richie\Home\LPCXpresso\digital_compass\lpc_board_nxp_lpcxpresso_1769\Debug" -Xlinker -Map="digital_compass.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "digital_compass_Debug.ld" -o "digital_compass.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) digital_compass.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "digital_compass.axf"; # arm-none-eabi-objcopy -v -O binary "digital_compass.axf" "digital_compass.bin" ; # checksum -p LPC1769 -d "digital_compass.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
