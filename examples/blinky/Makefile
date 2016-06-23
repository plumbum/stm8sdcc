TARGET=blinker
LIBSRC = $(LIBSRCDIR)/stm8s_beep.c

CC=sdcc
CFLAGS=-mstm8 --std-c99
MCU=STM8S003
DEFINES=-D$(MCU)

STDLIB=../../lib/STM8S_StdPeriph_Lib/Libraries/STM8S_StdPeriph_Driver

INCLUDEPATH=$(STDLIB)/inc/
LIBSRCDIR=$(STDLIB)/src/

BUILD_DIR=build


IHX=$(BUILD_DIR)/$(TARGET).ihx

all: build

build: $(IHX)

$(BUILD_DIR)/$(TARGET).ihx: $(TARGET).c
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -I$(INCLUDEPATH) -I. -L$(LIBSRCDIR) $(DEFINES) -o $(BUILD_DIR)/ $(LIBSRC)
	$(CC) $(CFLAGS) -I$(INCLUDEPATH) -I. -L$(LIBSRCDIR) $(DEFINES) -o $(BUILD_DIR)/ $< $(BUILD_DIR)/stm8s_beep.rel

%.hex: %.ihx
	packihx $< > $@

clean:
	rm -Rrf $(BUILD_DIR)

flash: $(IHX)
	stm8flash -c stlinkv2 -p stm8s003f3 -s flash -w $<

tags:
	ctags -R --c++-kinds=+p --fields=+iaS --extra=+q . $(INCLUDEPATH)

.PHONY: clean tags flash build

