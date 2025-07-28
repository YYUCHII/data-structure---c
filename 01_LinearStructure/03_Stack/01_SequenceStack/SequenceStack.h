#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义栈大小
#define Max 5

typedef int Element_t ;

typedef struct {
	Element_t data[Max];
	int top;
}Stack_t;

Stack_t * Create();

void Release(Stack_t * stack);

void push(Stack_t * stack , Element_t value);

Element_t pop(Stack_t * stack);