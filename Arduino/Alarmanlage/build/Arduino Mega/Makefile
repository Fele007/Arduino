ifeq ($(OS),Windows_NT)
SHELL = $(ComSpec)
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/Alarmanlage.cpp.o \
	project/Blinker.cpp.o \
	project/Buzzer.cpp.o \
	project/Gyro.cpp.o \
	project/Info.cpp.o \
	project/Matrix.cpp.o \
	project/RFID.cpp.o \
	project/Segments.cpp.o \
	project/ShiftRegister.cpp.o \
	project/TimerBank.cpp.o \

PLATFORM_CORE_OBJS = \
	core/abi.cpp.o \
	core/CDC.cpp.o \
	core/HardwareSerial.cpp.o \
	core/HardwareSerial0.cpp.o \
	core/HardwareSerial1.cpp.o \
	core/HardwareSerial2.cpp.o \
	core/HardwareSerial3.cpp.o \
	core/hooks.c.o \
	core/IPAddress.cpp.o \
	core/main.cpp.o \
	core/new.cpp.o \
	core/PluggableUSB.cpp.o \
	core/Print.cpp.o \
	core/Stream.cpp.o \
	core/Tone.cpp.o \
	core/USBCore.cpp.o \
	core/WInterrupts.c.o \
	core/wiring.c.o \
	core/wiring_analog.c.o \
	core/wiring_digital.c.o \
	core/wiring_pulse.c.o \
	core/wiring_pulse.S.o \
	core/wiring_shift.c.o \
	core/WMath.cpp.o \
	core/WString.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \
	libraries/MFRC522/1.4.4/src/MFRC522.cpp.o \
	libraries/MFRC522/1.4.4/src/MFRC522Extended.cpp.o \
	libraries/Wire/src/utility/twi.c.o \
	libraries/Wire/src/Wire.cpp.o \
	libraries/SPI/src/SPI.cpp.o \
	libraries/TinyMPU6050/0.4.3/src/TinyMPU6050.cpp.o \

TARGETS = \
	Alarmanlage.hex \

all: $(TARGETS)

Alarmanlage.hex: Alarmanlage.elf
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-objcopy" -O ihex -R .eeprom  "./Alarmanlage.elf" "./Alarmanlage.hex"

Alarmanlage.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega2560  -o "./Alarmanlage.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-size" -A "./Alarmanlage.elf"

project/Alarmanlage.cpp.o: ../../Alarmanlage.cpp project/Alarmanlage.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/Alarmanlage.cpp.d: ;

-include project/Alarmanlage.cpp.d 

project/Blinker.cpp.o: ../../Blinker.cpp project/Blinker.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/Blinker.cpp.d: ;

-include project/Blinker.cpp.d 

project/Buzzer.cpp.o: ../../Buzzer.cpp project/Buzzer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/Buzzer.cpp.d: ;

-include project/Buzzer.cpp.d 

project/Gyro.cpp.o: ../../Gyro.cpp project/Gyro.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/Gyro.cpp.d: ;

-include project/Gyro.cpp.d 

project/Info.cpp.o: ../../Info.cpp project/Info.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/Info.cpp.d: ;

-include project/Info.cpp.d 

project/Matrix.cpp.o: ../../Matrix.cpp project/Matrix.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/Matrix.cpp.d: ;

-include project/Matrix.cpp.d 

project/RFID.cpp.o: ../../RFID.cpp project/RFID.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/RFID.cpp.d: ;

-include project/RFID.cpp.d 

project/Segments.cpp.o: ../../Segments.cpp project/Segments.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/Segments.cpp.d: ;

-include project/Segments.cpp.d 

project/ShiftRegister.cpp.o: ../../ShiftRegister.cpp project/ShiftRegister.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/ShiftRegister.cpp.d: ;

-include project/ShiftRegister.cpp.d 

project/TimerBank.cpp.o: ../../TimerBank.cpp project/TimerBank.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

project/TimerBank.cpp.d: ;

-include project/TimerBank.cpp.d 


core/abi.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/CDC.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/HardwareSerial.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/HardwareSerial0.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/HardwareSerial1.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/HardwareSerial2.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/HardwareSerial3.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/hooks.c.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/IPAddress.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/main.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/new.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/PluggableUSB.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/Print.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/Stream.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/Tone.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/USBCore.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/WInterrupts.c.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/wiring.c.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/wiring_analog.c.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/wiring_digital.c.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/wiring_pulse.c.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/wiring_pulse.S.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/wiring_shift.c.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/WMath.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/WString.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d



libraries/MFRC522/1.4.4/src/MFRC522.cpp.o: C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src/MFRC522.cpp libraries/MFRC522/1.4.4/src/MFRC522.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

libraries/MFRC522/1.4.4/src/MFRC522.cpp.d: ;

-include libraries/MFRC522/1.4.4/src/MFRC522.cpp.d

libraries/MFRC522/1.4.4/src/MFRC522Extended.cpp.o: C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src/MFRC522Extended.cpp libraries/MFRC522/1.4.4/src/MFRC522Extended.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

libraries/MFRC522/1.4.4/src/MFRC522Extended.cpp.d: ;

-include libraries/MFRC522/1.4.4/src/MFRC522Extended.cpp.d

libraries/Wire/src/utility/twi.c.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src/utility/twi.c libraries/Wire/src/utility/twi.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

libraries/Wire/src/utility/twi.c.d: ;

-include libraries/Wire/src/utility/twi.c.d

libraries/Wire/src/Wire.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src/Wire.cpp libraries/Wire/src/Wire.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

libraries/Wire/src/Wire.cpp.d: ;

-include libraries/Wire/src/Wire.cpp.d

libraries/SPI/src/SPI.cpp.o: C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src/SPI.cpp libraries/SPI/src/SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

libraries/SPI/src/SPI.cpp.d: ;

-include libraries/SPI/src/SPI.cpp.d

libraries/TinyMPU6050/0.4.3/src/TinyMPU6050.cpp.o: C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src/TinyMPU6050.cpp libraries/TinyMPU6050/0.4.3/src/TinyMPU6050.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/felix/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/mega" -I"C:/Users/felix/.arduinocdt/libraries/MFRC522/1.4.4/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"C:/Users/felix/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"C:/Users/felix/.arduinocdt/libraries/TinyMPU6050/0.4.3/src" "$<" -o "$@"

libraries/TinyMPU6050/0.4.3/src/TinyMPU6050.cpp.d: ;

-include libraries/TinyMPU6050/0.4.3/src/TinyMPU6050.cpp.d

