include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard [^_]*.c)
#USRSOURCES = nombre.asm
#USEROBJECT =nombre.o

all: $(MODULE)

$(MODULE): $(SOURCES) $(USRSOURCES)
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld _loader.c $(SOURCES) -o ../$(MODULE)
	#$(GCC) $(GCCFLAGS) -I./include -T sampleCodeModule.ld _loader.c $(SOURCES) $(USEROBJECT) -o ../$(MODULE)

#$(USEROBJECT): 
#	$(ASM) $(ASMFLAGS) $(USRSOURCES) -o $(USEROBJECT)
clean:
	rm -rf *.o

.PHONY: all clean print
