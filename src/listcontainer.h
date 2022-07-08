
#pragma once

typedef struct {
	int* Buffer;
	size_t Length;
	size_t Capacity;
} ListContainer, LT;

LT* LTInit();
void LTDelete(LT* lt);
void LTAppend(LT* lt, int val);
void LTRemove(LT* lt, int idx);
