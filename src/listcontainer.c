
#include <stdlib.h>
#include "listcontainer.h"

/*
	Increases the amount of data the list is allocating in memory
	- Allocates in a binary fasion (2, 4, 8, 16, 32, etc.)
	- Designs to double the amount of memory it uses as the list expands
*/
static void AllocateMore(LT* lt) {
	size_t capacity = lt->Capacity > 0
		? lt->Capacity * 2
		: 2;
	int* buffer = malloc(capacity * sizeof(int));

	for (size_t i = 0; i < lt->Capacity; i++) {
		buffer[i] = lt->Buffer[i];
	}

	free(lt->Buffer);
	lt->Buffer = buffer;
	lt->Capacity = capacity;
}

/*
	Initialise a List struct
*/
LT* LTInit() {
	LT* lt = calloc(1, sizeof(LT));
	lt->Buffer = NULL;
	lt->Length = 0;
	lt->Capacity = 0;

	return lt;
}

/*
	Frees all of the resources uses by a List
*/
void LTDelete(LT* lt) {
	if (lt->Buffer != NULL) {
		free(lt->Buffer);
	}

	free(lt);
}

/*
	Append a value to the end of a list
	- Allocates more memory if it has reached the max amount its currently using
*/
void LTAppend(LT* lt, int val) {
	if (lt->Length >= lt->Capacity) {
		AllocateMore(lt);
	}

	lt->Buffer[lt->Length] = val;
	lt->Length++;
}

/*
	Remove a value at a specific index (starts at 0)
	- Does not shrink the actual size of the list in memory
*/
void LTRemove(LT* lt, int idx) {
	int* buffer = malloc(lt->Capacity * sizeof(int));

	size_t copyidx = 0;
	for (size_t i = 0; i < lt->Length; i++) {
		if (i != idx) {
			buffer[copyidx++] = lt->Buffer[i];
		}
	}

	lt->Buffer = buffer;
	lt->Length--;
}

