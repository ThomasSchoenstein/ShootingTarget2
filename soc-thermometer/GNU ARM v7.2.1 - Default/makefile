################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include protocol/bluetooth/lib/EFR32BG1B/GCC/subdir.mk
-include platform/emdrv/tempdrv/src/subdir.mk
-include platform/emdrv/sleep/src/subdir.mk
-include platform/Device/SiliconLabs/BGM1/Source/GCC/subdir.mk
-include platform/Device/SiliconLabs/BGM1/Source/subdir.mk
-include hardware/kit/common/drivers/subdir.mk
-include hardware/kit/common/bsp/subdir.mk
-include emlib/src/subdir.mk
-include app/bluetooth/common/util/subdir.mk
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
all: soc-thermometer.axf

# Tool invocations
soc-thermometer.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "C:\Users\jdoe8\Desktop\School\Embedded Systems\TargetCode\ShootingTarget2ElectricBoogaloo\ShootingTarget2\soc-thermometer\bgm111a256v2.ld" -Xlinker --gc-sections -Xlinker -Map="soc-thermometer.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o soc-thermometer.axf -Wl,--start-group "./app/bluetooth/common/util/infrastructure.o" "./application_properties.o" "./gatt_db.o" "./init_app.o" "./init_board.o" "./init_mcu.o" "./main.o" "./pti.o" "./targetFunctions.o" "./emlib/src/em_acmp.o" "./emlib/src/em_adc.o" "./emlib/src/em_aes.o" "./emlib/src/em_assert.o" "./emlib/src/em_burtc.o" "./emlib/src/em_can.o" "./emlib/src/em_cmu.o" "./emlib/src/em_core.o" "./emlib/src/em_cryotimer.o" "./emlib/src/em_crypto.o" "./emlib/src/em_csen.o" "./emlib/src/em_dac.o" "./emlib/src/em_dbg.o" "./emlib/src/em_dma.o" "./emlib/src/em_ebi.o" "./emlib/src/em_emu.o" "./emlib/src/em_eusart.o" "./emlib/src/em_gpcrc.o" "./emlib/src/em_gpio.o" "./emlib/src/em_i2c.o" "./emlib/src/em_iadc.o" "./emlib/src/em_idac.o" "./emlib/src/em_int.o" "./emlib/src/em_lcd.o" "./emlib/src/em_ldma.o" "./emlib/src/em_lesense.o" "./emlib/src/em_letimer.o" "./emlib/src/em_leuart.o" "./emlib/src/em_mpu.o" "./emlib/src/em_msc.o" "./emlib/src/em_opamp.o" "./emlib/src/em_pcnt.o" "./emlib/src/em_pdm.o" "./emlib/src/em_prs.o" "./emlib/src/em_qspi.o" "./emlib/src/em_rmu.o" "./emlib/src/em_rtc.o" "./emlib/src/em_rtcc.o" "./emlib/src/em_se.o" "./emlib/src/em_system.o" "./emlib/src/em_timer.o" "./emlib/src/em_usart.o" "./emlib/src/em_vcmp.o" "./emlib/src/em_vdac.o" "./emlib/src/em_wdog.o" "./hardware/kit/common/bsp/bsp_stk.o" "./hardware/kit/common/drivers/i2cspm.o" "./hardware/kit/common/drivers/si7013.o" "./hardware/kit/common/drivers/tempsens.o" "./hardware/kit/common/drivers/udelay.o" "./platform/Device/SiliconLabs/BGM1/Source/GCC/startup_bgm1.o" "./platform/Device/SiliconLabs/BGM1/Source/system_bgm1.o" "./platform/emdrv/sleep/src/sleep.o" "./platform/emdrv/tempdrv/src/tempdrv.o" "C:\Users\jdoe8\Desktop\School\Embedded Systems\TargetCode\ShootingTarget2ElectricBoogaloo\ShootingTarget2\soc-thermometer\platform\radio\rail_lib\autogen\librail_release\librail_config_bgm111a256v2_gcc.a" "C:\Users\jdoe8\Desktop\School\Embedded Systems\TargetCode\ShootingTarget2ElectricBoogaloo\ShootingTarget2\soc-thermometer\protocol\bluetooth\lib\EFR32BG1B\GCC\libpsstore.a" "C:\Users\jdoe8\Desktop\School\Embedded Systems\TargetCode\ShootingTarget2ElectricBoogaloo\ShootingTarget2\soc-thermometer\protocol\bluetooth\lib\EFR32BG1B\GCC\binapploader.o" "C:\Users\jdoe8\Desktop\School\Embedded Systems\TargetCode\ShootingTarget2ElectricBoogaloo\ShootingTarget2\soc-thermometer\protocol\bluetooth\lib\EFR32BG1B\GCC\libbluetooth.a" "C:\Users\jdoe8\Desktop\School\Embedded Systems\TargetCode\ShootingTarget2ElectricBoogaloo\ShootingTarget2\soc-thermometer\protocol\bluetooth\lib\EFR32BG1B\GCC\libmbedtls.a" "C:\Users\jdoe8\Desktop\School\Embedded Systems\TargetCode\ShootingTarget2ElectricBoogaloo\ShootingTarget2\soc-thermometer\platform\radio\rail_lib\autogen\librail_release\librail_module_efr32xg1_gcc_release.a" -lm -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: soc-thermometer.hex'
	arm-none-eabi-objcopy -O ihex "soc-thermometer.axf" "soc-thermometer.hex"
	@echo ' '

	@echo 'Building bin file: soc-thermometer.bin'
	arm-none-eabi-objcopy -O binary "soc-thermometer.axf" "soc-thermometer.bin"
	@echo ' '

	@echo 'Building s37 file: soc-thermometer.s37'
	arm-none-eabi-objcopy -O srec "soc-thermometer.axf" "soc-thermometer.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "soc-thermometer.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) soc-thermometer.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
