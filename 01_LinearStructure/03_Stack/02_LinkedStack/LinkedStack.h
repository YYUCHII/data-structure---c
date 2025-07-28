#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Element_t;

typedef struct _node{
	Element_t value;
	struct _node * next;
}Node_t;

typedef struct{
	Node_t * top;
	int num;
}Stack_t;

Stack_t * Create();

void Release(Stack_t *stack);

void push(Stack_t * stack,Element_t value);

Element_t pop(Stack_t *stack);