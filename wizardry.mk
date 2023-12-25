ifeq ($(OS),Windows_NT)
  EXE := .exe
else
  EXE :=
endif

LIB_DIR := $(shell dirname $(lastword $(MAKEFILE_LIST)))

LYN ?= lyn$(EXE)
INC_DIRS += $(LIB_DIR)/include
LYN_REF += $(LIB_DIR)/reference/fe6.ref.o

INC_FLAG := $(foreach dir, $(INC_DIRS), -I $(dir))

PREFIX ?= arm-none-eabi-
CC  := $(PREFIX)gcc
AS  := $(PREFIX)as

ARCH    := -mcpu=arm7tdmi -mthumb -mthumb-interwork
CFLAGS  := $(ARCH) $(INC_FLAG) -Wall -Wextra -Wno-unused-parameter -O2 -mtune=arm7tdmi -mlong-calls
ASFLAGS := $(ARCH) $(INC_FLAG)

%.o: %.s
	$(AS) $(ASFLAGS) -I $(dir $<) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

%.lyn.event: %.o
	$(LYN) $< $(LYN_REF) > $@
