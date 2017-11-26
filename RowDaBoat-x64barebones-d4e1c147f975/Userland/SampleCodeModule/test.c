#include <test.h>
#include <stdlib.h>

//void invalidOpCodeTest(void);
void test(int id) {
	switch(id) {
		case ZERODIVISION: zeroDivisionTest();
				break;
		// case INVALIDOPCODE: invalidOpCodeTest();
		// 		break;
	}
}

void zeroDivisionTest() {
	int i = 10/0;
}

