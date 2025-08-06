#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int * table;
	int num;
}Heap;

Heap * Create(int n);

void Release(Heap * heap);

void popHeap(Heap * heap,int value);

int pushHeap(Heap * heap);