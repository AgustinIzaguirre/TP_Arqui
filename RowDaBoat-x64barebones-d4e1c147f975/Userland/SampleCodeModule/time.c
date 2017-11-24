#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void time() {
	int hours = _int80(4,0,0,0,0,0);
	int minutes = _int80(3,0,0,0,0,0);
	int seconds = _int80(2,0,0,0,0,0);
	//printf("hours = %d\n", hours);

	printf(" %d:%d:%d\n", hours, minutes, seconds);
}