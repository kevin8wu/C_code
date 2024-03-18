# A Makefile for HelloWorld
PROJECT_NAME = HelloWorld

# Include Makefile
## include Makefil.include.gen


# Declaration
## SOURCE_FILE:= $(./src/*.c)
## BUILD_FILE:=$(./build/*)
TOP = .
GIT = git
SVN = svn
VER_CONTROL = $(GIT)
CC=gcc
## TOOL_DIR = /opt/toolchain/linux/bin
## OBJDUMP = $(TOOL_DIR)/sdk-elf-objdump
TARGET_CHIP_TYPE = asic
TARGET_CHIP_ID = rtl8852c
TARGET_CHIP_ECO_VERSION = a
TARGET_HCI_TYPE = USB
REMOVE = rm
FORCE_RECURSIVE = -rf
MKDIR = mkdir
CD = cd
COPY = cp
MAKE = make
BUILD_FOLDER = build
OUTPUT_FILENAME = $(PROJECT_NAME)
## BIN = $(BUILD_FILE)/$(OUTPUT_FILENAME).bin
## AXF = $(BUILD_FILE)/$(OUTPUT_FILENAME).axf
## LIB = $(BUILD_FILE)/$(OUTPUT_FILENAME).lib
## LD_SCRIPT = $(SOURCE_FILE)/$(OUTPUT_FILENAME).ld
SOURCE_DIR = $(TOP)
BUILD_DIR = $(TOP)/$(BUILD_FOLDER)


# Flags
SYSTEM_LEVEL_DEF =
SYSTEM_LEVEL_DEF += -D_MANUFACTURER_ID_=0x5d

ifeq ($(TARGET_CHIP_ID), rtl8852c)
	SYSTEM_LEVEL_DEF += -D_RTL8852C_SPECIFIC_
else ifeq ($(TARGET_CHIP_ID), rtl8852b)
	SYSTEM_LEVEL_DEF += -D_RTL8852B_SPECIFIC_
else
	SYSTEM_LEVEL_DEF += -D_RTL8852A_SPECIFIC_
endif

ifeq ($(TARGET_CHIP_ECO_VERSION), a)
    TARGET_ROM_VER_ = 0
else ifeq ($(TARGET_CHIP_ECO_VERSION), b)
    TARGET_ROM_VER_ = 1
else ifeq ($(TARGET_CHIP_ECO_VERSION), c)
    TARGET_ROM_VER_ = 2
else ifeq ($(TARGET_CHIP_ECO_VERSION), d)
    TARGET_ROM_VER_ = 3
else ifeq ($(TARGET_CHIP_ECO_VERSION), e)
    TARGET_ROM_VER_ = 4
else
    TARGET_ROM_VER_ = 0xff
endif
SYSTEM_LEVEL_DEF += -D_ROM_VER_=$(TARGET_ROM_VER_)
## -c: compile without link 
## -g: debug information
## -ansi: refer ansi
## -l: include file
## -Wall: display warning
COMPILE=-c
OPTIMIZE=-O2
OUTPUT=-o
HELP=--help


# Command and Dependency
all: create produce

## produce project
produce: $(BUILD_DIR)/$(OUTPUT_FILENAME).o
	$(CC) $(BUILD_DIR)/$(OUTPUT_FILENAME).o $(OUTPUT) $(BUILD_DIR)/$(OUTPUT_FILENAME).out
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(COMPILE) $^ $(OUTPUT) $@

## create folder to build
.PHONY: create
create:
	$(MKDIR) $(BUILD_DIR)

## execute the produced files
.PHONY: execute
execute:
	$(BUILD_DIR)/$(OUTPUT_FILENAME).out

## clean all of produced files
.PHONY: clean
clean:
	$(REMOVE) $(FORCE_RECURSIVE) $(BUILD_DIR)