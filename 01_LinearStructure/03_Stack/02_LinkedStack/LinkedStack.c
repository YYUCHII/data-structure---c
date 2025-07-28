#include"LinkedStack.h"

Stack_t * Create()
{
	Stack_t * stack = malloc(sizeof(Stack_t));

	stack->num = 0;

	//这里指向空这下面push有用
	stack->top = NULL;

	return stack;
}

void Release(Stack_t *stack)
{
	while(stack->top != NULL)
	{
		Node_t * t = stack->top->next;
		free(stack->top);
		stack->top = t;
	}

	free(stack);
}

//头插法，top指向新插入的节点
void push(Stack_t * stack,Element_t value)
{
	Node_t * new_node = malloc(sizeof(Node_t));
	new_node->value = value;

	new_node->next = stack->top;
	stack->top = new_node;

	stack->num++;
}

Element_t pop(Stack_t *stack)
{
	if(stack->top == NULL)
	{
		return -1;
	}

	Element_t temp = stack->top->value;

	Node_t * t = stack->top;
	stack->top = t->next;
	free(t);

	stack->num--;

	return temp;
}