#define ZERO_EXCEPTION_ID 0
#include <stdint.h>
#include <videoDriver.h>

static void zero_division();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
}

static void zero_division() {
	draw_word("warning: division by zero.",0,0);
	newLine();
}