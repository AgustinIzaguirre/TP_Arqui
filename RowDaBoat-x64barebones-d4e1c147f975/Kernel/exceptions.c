#include <stdint.h>
#include <videoDriver.h>
#include <exceptions.h>


char* registers[REGISTERS]={"r15", "r14", "r13", "r12", "r11", "r10","r9","r8", "rsi", "rdi", "rbp", "rdx", "rcx", "rbx", "rax"};

void exceptionDispatcher(int exception, uint64_t* rsp) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division(rsp);
	else if(exception == INVALID_OPCODE_EXCEPTION_ID)
		invalid_opcode(rsp);
	else if(exception == OVERFLOW_ID)
		overflow(rsp);
	else if(exception == GENERAL_PROTECTION_FAULT)
		general_protection_fault(rsp);
	else if(exception == BREAKPOINT)
		breakpoint(rsp);
}

static void zero_division(uint64_t* rsp) {
	draw_word("warning: zero division.");
	newLine();
	printRegisters(rsp);
}


static void invalid_opcode(uint64_t* rsp) {
	draw_word("warning: invalid opcode.");
	newLine();
	printRegisters(rsp);
}

static void overflow(uint64_t* rsp){	
	draw_word("warning: overflow.");
	newLine();
	printRegisters(rsp);
}


static void general_protection_fault(uint64_t* rsp){
	draw_word("warning: general protection fault.");
	newLine();
	printRegisters(rsp);
}

static void breakpoint(uint64_t* rsp){
	draw_word("warning: breakpoint.");
	newLine();
	printRegisters(rsp);	
}

static void printRegisters(uint64_t* rsp) {
	for(int i = 0; i<REGISTERS; i++) {
		draw_word(registers[i]);
		draw_word(":  ");
		printHexaNumber(*rsp);
		rsp--;
		newLine();
	}
}

