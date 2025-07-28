#include"SequenceStack.h"

int main()
{
	Stack_t * stack = Create();

	push(stack, 1);
	push(stack,2);
	push(stack,3);
	push(stack,4);
	push(stack,5);
	
	printf("pop = %d\n",pop(stack));

	printf("top = %d",stack->top);
	Release(stack);
}