#include"LinkedQueue.h"

int main()
{
	Queue_t * queue = Create();

	push(queue,1);
	push(queue,2);

	printf("pop = %d\n",pop(queue));
	printf("pop = %d\n",pop(queue));

	printf("num = %d",queue->num);

	Release(queue);
}