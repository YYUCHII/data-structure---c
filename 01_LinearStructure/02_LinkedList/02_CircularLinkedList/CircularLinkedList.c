#include"CircularLinkedList.h"

List_t * Create()
{
	List_t * list = malloc(sizeof(List_t));

	list->head.next = list->rear = &list->head;
	list->num = 0;

	return list;
}

void Release(List_t * list)
{
	Node_t * p = &list->head;

	while(p->next != &list->head)
	{
		Node_t * t = p->next;
		p->next = t->next;
		free(t);
		//list->num--;
	}

	free(list);
}

Node_t * createNode(Element_t value)
{
	Node_t * new_node = malloc(sizeof(Node_t));

	new_node->next = NULL;
	new_node->value = value;

	return new_node;
}

void head_insert(List_t * list , Element_t value)
{
	Node_t * p = &list->head;

	Node_t * new_node = createNode(value);

	if(list->rear == p) list->rear = new_node;

	new_node->next = p->next;
	p->next = new_node;

	list->num++;
}

void tail_insert(List_t * list , Element_t value)
{
	Node_t * new_node = createNode(value);

	new_node->next = list->rear->next;
	list->rear->next = new_node;

	list->rear = new_node;

	list->num++;
}

void Delete(List_t * list , Element_t value)
{
	Node_t * p = &list->head;

	while(p->next != &list->head)
	{
		if(p->next->value == value) break;
		p = p->next;
	}

	if(p->next == &list->head)
	{
		printf("删除元素不存在\n");
		return;
	}

	Node_t * t = p->next;
	if(t->next == &list->head) list->rear = p;
	p->next = t->next;
	free(t);

	list->num--;
}