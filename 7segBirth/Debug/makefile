################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
7segBirth.lss \

FLASH_IMAGE += \
7segBirth.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 7segBirth.elf secondary-outputs

# Tool invocations
7segBirth.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,7segBirth.map -mmcu=atmega32 -o "7segBirth.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

7segBirth.lss: 7segBirth.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 7segBirth.elf  >"7segBirth.lss"
	@echo 'Finished building: $@'
	@echo ' '

7segBirth.hex: 7segBirth.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 7segBirth.elf  "7segBirth.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 7segBirth.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 7segBirth.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 7segBirth.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
