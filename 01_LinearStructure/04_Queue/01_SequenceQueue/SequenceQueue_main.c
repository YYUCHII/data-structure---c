#include"SequenceQueue.h"

int main()
{
	Queue_t * queue = Create();

	push(queue, 1);
	push(queue,2);
	push(queue, 3);
	push(queue,4);
	push(queue, 5);

	printf("pop = %d\n",pop(queue));
	printf("pop = %d\n",pop(queue));
	printf("pop = %d\n",pop(queue));
	printf("pop = %d\n",pop(queue));
	printf("pop = %d\n",pop(queue));

	Release(queue);
}