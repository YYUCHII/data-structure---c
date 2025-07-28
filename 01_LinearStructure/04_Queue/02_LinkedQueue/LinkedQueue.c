#include"LinkedQueue.h"

Queue_t * Create()
{
	Queue_t * queue = malloc(sizeof(Queue_t));

	queue->front = queue->rear = NULL;
	queue->num = 0;

	return queue;
}

void Release(Queue_t * queue)
{
	while(queue->front != NULL)
	{
		Node_t * t = queue->front->next;
		free(queue->front);
		queue->front =t;
	}

	free(queue);

}

void push(Queue_t * queue , Element_t value)
{
	Node_t * new_node = malloc(sizeof(Node_t));
	new_node->value = value;
	new_node->next = NULL;

	if(queue->front == NULL)
	{
		queue->front = queue->rear = new_node;
		queue->num++;
		return;
	}

	//因为每个新节点的next都是NULL，就不需要 new_node->next = queue->rear->next;
	queue->rear->next = new_node;
	queue->rear = new_node;

	queue->num++;
}

Element_t pop(Queue_t * queue)
{
	if(queue->front == NULL)
	{
		printf("queue is empty\n");
		return -1;
	}

	Element_t temp = queue->front->value;

	Node_t * t = queue->front->next;
	free(queue->front);
	queue->front = t;

	queue->num--;

	return temp;
}