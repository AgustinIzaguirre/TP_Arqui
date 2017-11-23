/* sampleCodeModule.c */
#include <plotter.h>
//#include "./../../Kernel/include/videoDriver.h"
char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;
int _int80(uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t);
extern char bss;
extern char endOfBinary;

int main() {
	memset(&bss,0,&endOfBinary - &bss);
	printf("Hola como va\n");
	printf("tengo %d anos.",22);
	// char * frase = "hola como va";
	// int80(1,0,frase,5,0,0);

	//draw_word("Entro en sampleCodeModuleAddress",0,0);
	// char * frase = "hola como va";
	
 // 	char hora[2] = {0};
 // 	int horas = _int80(4,0,0,0,0,0);
 // 	hora[1] = horas%10 + 48;
 // 	hora[0] = horas/10 + 48;
 // 	return _int80(1,0,hora,2,0,0);
	
	return 10;
	//return 9;
	//drawFunction(1,0,0);
	// for(int i =0 ; i <200; i++) {
	// 	draw
	// }
	// char * f = "hola como va";
	// int80(0,f,10,0,0,0);
	// // //All the following code may be removed 
	// *v = 'X';
	// *(v+1) = 0x74;

	// //Test if BSS is properly set up
	// if (var1 == 0 && var2 == 0)
	// 	return 0xDEADC0DE;

	//return 0xDEADBEEF;
}