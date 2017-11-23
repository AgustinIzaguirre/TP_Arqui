include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard [^_]*.c)
USRSOURCES=systemCaller.asm
USROBJECT=systemCaller.o

all: $(MODULE)

$(MODULE): $(SOURCES) $(USROBJECT)
	$(GCC) $(GCCFLAGS) -I./include -T sampleCodeModule.ld _loader.c $(SOURCES) $(USROBJECT) -o ../$(MODULE)

$(USROBJECT):
	$(ASM) $(ASMFLAGS) ./asm/$(USRSOURCES) -o $(USROBJECT)

clean:
	rm -rf *.o

.PHONY: all clean print