#include <stdint.h>
#include <videoDriver.h>


uint64_t sysTest(int,int,int,int);

void syscallsTest() {
	int rax = 5,rdi,rsi,rdx;
	uint64_t result;
	//draw_word("Entro ",0,10);

	result = sysTest(rax,rdi,rsi,rdx);
	draw_word("Entro ",0,10);
	char decena = (result%100)/10 + '0';
	char unidad = result%10 + '0';
	draw_char(decena);
	draw_char(unidad);
}