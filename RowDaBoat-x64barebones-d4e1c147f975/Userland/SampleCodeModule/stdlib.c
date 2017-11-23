//stdlib.c
#include <stdint.h>
#include <stdlib.h>
#include <plotter.h>
#include <stdarg.h>
extern uint64_t int80(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9);

int isAlpha(char c){
	return ((c>='A' && c<='Z') || (c>='a' && c<='z'));
}

int isNum(char c){
	return (c>='0' && c<='9');
}

int isSpace(char c){
	return (c=' ');
}

void intToStr(int num,char * ret){
	int dig=0;
	char aux;
	if(num!=0){
		if(num<0){
			num=-num;
			ret[0]='-';
			dig++;
		}
		while(num!=0){
			ret[dig]=(num%10)+'0';
			num=num/10;
			dig++;
		}
		for(int x=0;x<dig/2;x++){
			aux=ret[x];
			ret[x]=ret[dig-x-1];
			ret[dig-x-1]=aux;
		}
		ret[dig]=0;
	}else{
		ret[0]='0';
	}	
}
// void strrev(char * str){
// 	int length= strlen(str);
// 	char aux[length];
// 	int i;
// 	strcpy(str,aux);

// 	for (i = 0; i < length; i++) {
// 		str[length - 1 - i] = aux[i];
// 	}
// }

int strlen(const char * str){
	int i=0;
	while(str[i]!= '\0'){
		i++;
	}
	return i;
}

int strcpy(char *from, char *to){
	int i=0;
	for (i=0;from[i]!='\0';i++){
		to[i]=from[i];
	}
	return i;
}

void printf(const char * str,...){
	char num[12];
	va_list valist;
	va_start (valist,str);
	int length=strlen(str);
	int state=0;
	for(int x=0;x<length;x++){
		if(state==0){
			if(str[x]!= '%')
				putchar(str[x]);
			else
				state=1;
		}else{
			switch(str[x]){
				case 'd':
					intToStr(va_arg (valist, int),num);
					int index=0;
					while(num[index]!=0)
						putchar(num[index++]);
					state=0;
					break;
				case 'c':
					putchar((char)(va_arg(valist,int)));
					state=0;
					break;
				case 's':
					printf(va_arg(valist, char*));
					state = 0;
					break;
				default:	
					putchar('%');
					putchar(str[x]);
					state=0;
					break;
			}
		}

	}	
	va_end(valist);
}

void putchar(const char c){
	int80(3,1,c,1,0,0);
}
