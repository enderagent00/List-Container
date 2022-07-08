
#include <stdio.h>
#include "listcontainer.h"

int main(void) {
	LT* lt = LTInit();

	for (int i = 0; i < 25; i++) {
		LTAppend(lt, i);
	}

	for (size_t i = 0; i < lt->Length; i++) {
		printf("[%d] Value: %d\n", i, lt->Buffer[i]);
	}
	
	printf("-------------------------\n");
	printf("Length: %d\n", lt->Length);
	printf("Capacity: %d\n", lt->Capacity);

	LTDelete(lt);
}


