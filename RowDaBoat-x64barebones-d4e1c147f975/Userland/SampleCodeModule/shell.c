#include <shell.h>
#include <stdlib.h>
#include <stdint.h>
#include <plotter.h>
#include <date.h>
#include <echo.h>
#include <time.h>
#include <clear.h>
#include <help.h>
#include <color.h>

uint64_t _int80(uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t);

char command [COMMAND_MAX_LENGTH];
char args[COMMANDS_MAX_ARGS+1];
int functionArgs[MAX_QUADRATIC_INTS];
int width = 0;
int height = 0;

void shell(){
	//drawFunction(2,0,0);
	setUpShell();
	int command; 
	printPrompt();
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
							setUpShell(); 
					break;
				case HELP: help();
					break;
				case ECHO: echo(args);
					break;
				case LINEAR:  functionScreen(0,functionArgs[0],functionArgs[1]);
						break;
				case QUADRATIC: functionScreen(functionArgs[0],functionArgs[1],functionArgs[2]);
						break;
				case COLOR:  color(functionArgs[0],functionArgs[1],functionArgs[2]);
						break;
			}
		}
		if(command)
			printPrompt();
	}
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
	int c;
	int i = 0;
	while((c = getchar())!='\n' && (i==0 || c!=' ')) {
		if(c!='\b')
			putchar(c);
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

	if(c == ' '){
		putchar(c);
		if(readArgs(args)==1)
			return getCommands();
	}
	else {
		args[0]=0;
	}

	if(i<COMMAND_MAX_LENGTH) {
		command[i] = 0;	
		int argsLength = strlen(args);
		if(strcmp(command,"time") && argsLength == 0){
			return TIME;
		}	
		else if (strcmp(command,"date") && argsLength == 0){
			return DATE;
		}
		else if (strcmp(command,"clear") && argsLength == 0){
			return CLEAR;
		}
		else if (strcmp(command,"help") && argsLength == 0){
			return HELP;
		}
		else if (strcmp(command,"exit") && argsLength == 0){
			clear();
			return EXIT;
		}
		else if(strcmp(command,"echo")) {
			return ECHO;
		}
		else if(strcmp(command,"linear")){
			if(getInts(MAX_LINEAR_INTS) != MAX_LINEAR_INTS)
			 	return COMMANDS_QUANTITY;
			return LINEAR;
		}
		else if(strcmp(command,"quadratic")){
			if(getInts(MAX_QUADRATIC_INTS) != MAX_QUADRATIC_INTS)
			 	return COMMANDS_QUANTITY;
			return QUADRATIC;
		}
		else if(strcmp(command,"color")){
			if(getInts(MAX_COLOR_INTS) != MAX_COLOR_INTS || !valid(0,256,MAX_COLOR_INTS))
				return COMMANDS_QUANTITY;
			//printf("b = %d, g = %d")
			return COLOR;
		}

	}
	return COMMANDS_QUANTITY;
}

int readArgs(char * args) {
	int c;
	int i = 0;
	while((c = getchar())!='\n') {
		if(c!='\b') {
			putchar(c);
			if(i < COMMANDS_MAX_ARGS){
		 		args[i] = c;
				i++;
			}
		}
		else if(i>0 && i<COMMANDS_MAX_ARGS) {
		 		i--;
		}
		else {
			return 1;
		}
	}
	args[i] = 0;
	return 0;
}

int getInts(int totalArgs) {
	int i;
	int j=0;
	int sign = 0;
	for(i=0; args[i]; i++){
		if(args[i]!=' ' && !isNum(args[i])){
			if(args[i] == '-')
				sign =1;
			else
				return MAX_QUADRATIC_INTS + 1;
		}
		else if(isNum(args[i])){
			if(j < totalArgs){
				functionArgs[j] = (sign==1)? -getNumber(args,&i) : getNumber(args,&i);
				j++;
			}
			else
				return MAX_QUADRATIC_INTS + 1;
		}
	}
	return j;
}

int getNumber(char* args, int* pos){
	int num = 0;
	while(isNum(args[*pos])){
		num = num*10 + (args[*pos]-48);
		(*pos)++;
	}
	(*pos)--;
	return num;
}

void functionScreen(int a, int b, int c) {
	clear();
	printf("Presione q para salir.\n");
	drawFunction(a,b,c);
	int l;
	while((l = getchar())!='q');
	clear();
	setUpShell();
}

int valid(int from,int to,int size){
	int i;
	for(i=0; i <size; i++){
		if(functionArgs[i] < from || functionArgs[i] > to)
			return 0;
	}
	return 1;
}