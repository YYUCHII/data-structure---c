#include"SequenceStack.h"

Stack_t * Create()
{
	Stack_t * stack = malloc(sizeof(Stack_t));

	stack->top = 0;

	return stack;
}

void Release(Stack_t * stack)
{
	free(stack);
}

void push(Stack_t * stack , Element_t value)
{
	if(stack->top == Max)
	{
		printf("stack is full\n");
		return;
	}

	stack->data[stack->top] = value;
	stack->top++;
}

Element_t pop(Stack_t * stack)
{
	if(stack->top == 0)
	{
		printf("stack is empty\n");
		return -1;
	}

	stack->top--;
	return stack->data[stack->top];
}