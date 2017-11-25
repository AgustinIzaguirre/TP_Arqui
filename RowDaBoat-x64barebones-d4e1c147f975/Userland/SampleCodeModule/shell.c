#include <shell.h>
#include <stdlib.h>
#include <stdint.h>
#include <plotter.h>
#include <date.h>
#include <echo.h>
#include <time.h>
#include <clear.h>
#include <help.h>

uint64_t _int80(uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t);
int width = 0;
int height = 0;
void shell(){
	//draw_horizontalLine(0, 400, 100);
	setUpShell();
	int command; 

	while(command = getCommands()) {
		if(command >= COMMANDS_QUANTITY) {
			printf("command not found\n");
		}
		else {
			switch(command){
				case TIME: time();
					break;
				case DATE: date();
					break;
				case CLEAR: clear(); 
					break;
				case HELP: help();
					break;
					//echo, cuadratic
			}
		}
	}

	//printPrompt();
	//printf("height = %d\nwidth = %d\n",height,width);
}

void setUpShell() {
	width = (int)_int80(11,0,0,0,0,0);
	height = (int)_int80(11,1,0,0,0,0);
	_int80(12,0,height - 1*CHAR_HEIGHT,0,0,0);
}

void printPrompt(){
	printf("$>");
}

int getCommands(){
	printPrompt();
	int c;
	char command [COMMAND_MAX_LENGTH];
	int i = 0;
	while((c = getchar())!='\n') {
		 if(i!=0 || c != ' ') {
		 	if(c == '\b'){
		 		if(i > 0)
		 			i--;
		 	}
		 	else {
		 		command[i] = c;
				i++;
			}
		 }
	}
	if(i<COMMAND_MAX_LENGTH) {
		
		if(strcmp(command,"time")){
			return TIME;
		}	
		else if (strcmp(command,"date")){
			return DATE;
		}
		else if (strcmp(command,"clear")){
			return CLEAR;
		}
		else if (strcmp(command,"help")){
			return HELP;
		}
		else if (strcmp(command,"exit")){
			clear();
			return EXIT;
		}
	}
	return COMMANDS_QUANTITY;
}