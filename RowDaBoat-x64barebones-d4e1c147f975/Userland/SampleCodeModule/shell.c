#include <shell.h>
#include <stdlib.h>
#include <stdint.h>
#include <date.h>
#include <echo.h>
#include <time.h>]

uint64_t _int80(uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t);
int width = 0;
int height = 0;
void shell(){
	width = (int)_int80(11,0,0,0,0,0);
	height = (int)_int80(11,1,0,0,0,0);
	_int80(12,0,height - 2*CHAR_HEIGHT,0,0,0);

	printPrompt();
	printf("height = %d\nwidth = %d\n",height,width);
}

void printPrompt(){
	printf("$>");
	time();
	date();
}