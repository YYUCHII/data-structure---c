#include"LinkedStack.h"

int main()
{
	Stack_t * stack = Create();

	push(stack, 1);
	push(stack, 2);

	printf("pop = %d\n",pop(stack));
	printf("pop = %d\n",pop(stack));
	printf("pop = %d\n",pop(stack));

	Release(stack);
}