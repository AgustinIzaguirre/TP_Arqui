#ifndef _SHELL_H_
#define _SHELL_H_

#define CHAR_HEIGHT 16

#define EXIT 0
#define TIME 1
#define DATE 2
#define CLEAR 3
#define HELP 4
#define COMMAND_MAX_LENGTH 6
#define COMMANDS_QUANTITY 5

void shell(void);
void setUpShell(void) ;
void printPrompt(void);
int getCommands(void);

#endif