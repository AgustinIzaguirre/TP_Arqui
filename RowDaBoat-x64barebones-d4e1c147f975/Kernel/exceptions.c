#include <stdint.h>
#include <videoDriver.h>

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_EXCEPTION_ID 1
#define REGISTERS 15
static void zero_division(uint64_t** rsp);
static void invalid_opcode(uint64_t** rsp);

char* registers[REGISTERS]={"r15", "r14", "r13", "r12", "r11", "r10","r9","r8", "rsi", "rdi", "rbp", "rdx", "rcx", "rbx", "rax"};

void exceptionDispatcher(int exception, uint64_t** rsp) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division(rsp);
	else if(exception == INVALID_OPCODE_EXCEPTION_ID)
		invalid_opcode(rsp);
}

static void zero_division(uint64_t** rsp) {
	draw_word("warning: division by zero.",0,0);
	newLine();
	for(int i = 0; i<REGISTERS; i++) {
		draw_word(registers[i],0,0);
		draw_word(":  ",0,0);
		printHexaNumber(*rsp);
		rsp--;
		newLine();
	}
}


static void invalid_opcode(uint64_t** rsp) {
	draw_word("warning: invalid opcode.",0,0);
	newLine();
	for(int i = 0; i<REGISTERS; i++) {
		draw_word(registers[i],0,0);
		draw_word(":  ",0,0);
		printHexaNumber((**rsp));
		rsp--;
		newLine();
	}
}