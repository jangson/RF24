
# Define programs and commands.
SHELL = sh
CC = avr-gcc
LD = avr-ld
# CXX = avr-g++
CXX = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size
AR = avr-ar rcs
NM = avr-nm
REMOVE = rm -f
REMOVEDIR = rmdir
COPY = cp
WINSHELL = cmd

ARCH = AVR8
MCU = atmega32u4

LIBNAME=avr-nrf24.a
DRIVER=tmk
DRIVER_DIR=utility/tmk



# PROJECT_NAME 	= $(PWD:B) ;
# PROJECT_DIR 	= . ;
# PROJECT_LIBS    = EEPROM SPI RF24 ; 
# 
# OUT_DIR = ojam ;
# F_CPU 		= 16000000 ;
# MCU             = atmega328p ;
# PORTS           = /dev/tty.usbserial-A600eHIs /dev/tty.usbserial-A40081RP /dev/tty.usbserial-A9007LmI ;
# 
# UPLOAD_RATE 	= 57600 ;
# AVRDUDE_PROTOCOL = stk500v1 ;
# COM 		= 33 ;
# 
# Host-specific overrides for locations 
# if $(OS) = MACOSX 
# {
# ARDUINO_VERSION	= 22 ;
# OLD_DIR 	= /opt/arduino-0021 ;
# AVR_TOOLS_PATH 	= $(OLD_DIR)/hardware/tools/avr/bin ;
# AVRDUDECONFIG_PATH = $(OLD_DIR)/hardware/tools/avr/etc ;
# ARDUINO_DIR 	= /opt/Arduino ;
# ARDUINO_AVR 	= /usr/lib/avr/include ;
# }

# Where is everything?
# ARDUINO_VERSION	?= 22 ;
# AVR_TOOLS_PATH 	?= /usr/bin ;
# ARDUINO_DIR 	?= /opt/arduino-00$(ARDUINO_VERSION) ;
# ARDUINO_AVR 	?= $(ARDUINO_DIR)/hardware/tools/avr/avr/include/avr ;
# AVRDUDECONFIG_PATH ?= $(ARDUINO_DIR)/hardware/tools ;
# ARDUINO_CORE 	= $(ARDUINO_DIR)/hardware/arduino/cores/arduino ;
# ARDUINO_LIB 	= $(ARDUINO_DIR)/libraries ;
# SKETCH_LIB      = $(HOME)/Source/Arduino/libraries ;
# AVR_CC  	= $(AVR_TOOLS_PATH)/avr-gcc ;
# AVR_CXX  	= $(AVR_TOOLS_PATH)/avr-g++ ;
# AVR_LD  	= $(AVR_TOOLS_PATH)/avr-gcc ;
# AVR_OBJCOPY 	= $(AVR_TOOLS_PATH)/avr-objcopy ;
# AVRDUDE 	= $(AVR_TOOLS_PATH)/avrdude ;

# DEFINES  	= F_CPU=$(F_CPU)L ARDUINO=$(ARDUINO_VERSION) VERSION_H ;
# CTUNING  	= -ffunction-sections -fdata-sections
# CXXTUNING  	= -fno-exceptions -fno-strict-aliasing 
# override CFLAGS = -Os -Wall -Wextra -mmcu=$(MCU)
# CXXFLAGS  	= $(CFLAGS) $(CXXTUNING)
# LDFLAGS  	+= -Os -lm -Wl,--gc-sections -mmcu=$(MCU)
