#include <naiveConsole.h>
#include <lib.h>
#include <videoDriver.h> 
#include <KeyboardDriver.h>
#include <KeyboardMap.h>

int isAlpha(char);

static uint8_t status = 0;
uint8_t buffer[256];
uint16_t index = 0;
uint16_t read = 0;

void keyboard_handler() {
	char l = getKey();

	if(l >0) {
		if(kbdus[l]) {
			buffer[index] = kbdus[l];
			incrementIndex();

			if(status & 1<<SHIFT){
				draw_char(shiftedkey[l]);
			}
			else if(status & 1<<CAPSLOCK){
				draw_char(capsKey[l]);
			}
			else
				draw_char(kbdus[l]);
		}
		else {
			if(l == LSHIFTCODE || l == RSHIFTCODE)  //shift pressed
				status = status | 1<<SHIFT;
			else if(l == CAPSLOCKCODE) {  //caps pressed
				if(status & 1<<CAPSLOCK)
					status = status & (~(1<<CAPSLOCK));
				else
					status = status | 1<<CAPSLOCK;		
			}
			else if(l == BACKSPACECODE) {
				erase_char();
			}
			else if(l == NEWLINECODE)
				newLine();
		}	
	}
	else {
	 	if(l+128 == LSHIFTCODE || l+128 == RSHIFTCODE) //shift removed
			status = status & (~(1<<SHIFT));

	}
}

void incrementIndex(){
	if((index + 1 %256) != read) {
		index ++;
		index = index%256;
	}
}

void incrementRead(){
	if(read != index){
		read ++;
		read = read % 256;
	}
}

int getChar() {
	_sti();
	if(read == index)
		return -1;
	int c = buffer[read];
	incrementRead();
	return c;
}