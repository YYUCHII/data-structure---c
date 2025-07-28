#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

typedef int Element_t;

typedef struct _node{
	Element_t value;
	struct _node * next;
}Node_t;

typedef struct {
	Node_t * front;
	Node_t * rear;
	int num;
}Queue_t;

Queue_t * Create();

void Release(Queue_t * queue);

void push(Queue_t * queue , Element_t value);

Element_t pop(Queue_t * queue);