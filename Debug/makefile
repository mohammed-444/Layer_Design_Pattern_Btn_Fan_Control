################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include source_main/MCAL/timer/subdir.mk
-include source_main/MCAL/spi/subdir.mk
-include source_main/MCAL/pwm/subdir.mk
-include source_main/MCAL/gpio/subdir.mk
-include source_main/MCAL/EXT_INTERRUPT/subdir.mk
-include source_main/ECUAL/lcd/subdir.mk
-include source_main/ECUAL/dc_motor/subdir.mk
-include source_main/ECUAL/button/subdir.mk
-include source_main/ECUAL/TC72/subdir.mk
-include source_main/APP/subdir.mk
-include source_main/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := layer_design_pattern_btn_fan_control
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
layer_design_pattern_btn_fan_control.lss \
layer_design_pattern_btn_fan_control.lss \
layer_design_pattern_btn_fan_control.lss \
layer_design_pattern_btn_fan_control.lss \

SIZEDUMMY += \
sizedummy \
sizedummy \
sizedummy \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: layer_design_pattern_btn_fan_control.elf secondary-outputs

# Tool invocations
layer_design_pattern_btn_fan_control.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,layer_design_pattern_btn_fan_control.map -mmcu=atmega16 -o "layer_design_pattern_btn_fan_control.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

layer_design_pattern_btn_fan_control.lss: layer_design_pattern_btn_fan_control.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S layer_design_pattern_btn_fan_control.elf  >"layer_design_pattern_btn_fan_control.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: layer_design_pattern_btn_fan_control.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 layer_design_pattern_btn_fan_control.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) layer_design_pattern_btn_fan_control.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
