#include <stdint.h>
#include <videoDriver.h>

uint64_t sys_write(unsigned int fd, const char* buffer, uint64_t count);
uint8_t sys_seconds(void);
uint8_t sys_mins(void);
uint8_t sys_hours(void);
uint32_t sys_year(void);
uint8_t sys_month(void);
uint8_t sys_day(void);

uint8_t getSeconds(void);
uint8_t getMinutes(void);
uint8_t getHours(void);
uint32_t getYear(void);
uint8_t getMonth(void);
uint8_t getDay(void);

uint64_t sys_paint(uint64_t x, uint64_t y, uint64_t color, uint64_t r8,uint64_t r9);
uint64_t sys_clear(void);
uint64_t sys_writeChar(uint64_t fd,uint64_t buffer, uint64_t count, uint64_t x, uint64_t y);
uint64_t sys_getScreenInfo(uint64_t rdi);


uint64_t systemCallDispatcher(uint64_t rax, uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t r8, uint64_t r9) {
		uint64_t result;
		draw_word("Entro en el dispatcher",0,0);
		switch(rax) {
			// case 0:
			// 	return sys_read(rdi,rsi,rdx);
			case 1:
				 result = sys_write(rdi,rsi,rdx);
				 break;
			case 2:
				result =(uint64_t)sys_seconds();
				break;
			case 3:
				result=(uint64_t)sys_mins();
				break;
			case 4:
				result =(uint64_t)sys_hours();
				break;
			case 5:
				result = sys_year();
				break;
			case 6:
				result = sys_month();
				break;
			case 7:
				result =  sys_day();
				break;
			case 8:
				result =  sys_paint(rdi,rsi,rdx,r8,r9);
				break;
			case 9:
				result =  sys_clear();
				break;
			case 10:
				result =  sys_writeChar(rdi,rsi,rdx,r8,r9);
				break;
			case 11:
				result =  sys_getScreenInfo(rdi);
				break;
		}
		// char c = rax;
		// int80(1,0,&c,1,0,0);

		return result;
}

uint64_t sys_write(unsigned int fd, const char* buffer, uint64_t count) {
	int i = 0;
	while(i<count){
		draw_char(buffer[i]);
		i++;
	}
	return count;
}

uint8_t sys_seconds(){
	uint8_t seconds = getSeconds();
	return seconds;
}


uint8_t sys_mins(){
	uint8_t minutes = getMinutes();
	return minutes;
}

uint8_t sys_hours(){
	uint8_t hours = getHours();
	return hours;
}


uint32_t sys_year(){
	uint32_t year = getYear();
	return year;
}


uint8_t sys_month(){
	uint8_t month = getMonth();
	return month;
}

uint8_t sys_day(){
	uint8_t day = getDay();
	return day;
}

//
uint64_t sys_paint(uint64_t x, uint64_t y, uint64_t color, uint64_t r8,uint64_t r9){
	Color c=hexaToColor(color);
	draw_pixel_with_color(x,y,c);
	return 0;
}


uint64_t sys_clear(){
	cls();
	return 0;
}

// uint64_t sys_read(uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8,uint64_t r9){
// 	return 0;
// }
uint64_t sys_writeChar(uint64_t fd,uint64_t buffer, uint64_t count, uint64_t x, uint64_t y){
	int i=0;
	char *charbuffer=(char*)buffer;
	draw_char_position(charbuffer[0], x, y);
	return 0;
}

uint64_t sys_getScreenInfo(uint64_t rdi){
	switch(rdi){
		case 0:
			return getScreenWidth();
		case 1:
			return getScreenHeigth();
	}
	return 0;
}//

// uint64_t sys_read(unsigned int fd, const char* buffer, uint64_t count) {
// 	int i = 0;
// 	while(i<count){
// 		draw_char(buffer[i]);
// 		i++;
// 	}
// 	return count;
//}