#include"SequenceQueue.h"

Queue_t * Create()
{
	Queue_t * queue = malloc(sizeof(Queue_t));

	queue->front = queue->rear = 0;

	return queue;
}

void Release(Queue_t* queue)
{
	free(queue);
}

void push(Queue_t * queue , Element_t value)
{
	if((queue->rear+1)%Max == queue->front)
	{
		printf("queue is full\n");
		return;
	}

	queue->rear = (queue->rear+1)%Max;
	queue->data[queue->rear] = value;
}

Element_t pop(Queue_t * queue)
{
	if(queue->front == queue->rear)
	{
		printf("queue is empty\n");
		return -1;
	}

	queue->front = (queue->front+1)%Max;
	
	return queue->data[queue->front];
}