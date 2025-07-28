#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

#define Max 5

typedef int Element_t;

typedef struct{
	Element_t data[Max];
	int front;
	int rear;
}Queue_t;

Queue_t * Create();

void Release(Queue_t* queue);

void push(Queue_t * queue , Element_t value);

Element_t pop(Queue_t * queue);