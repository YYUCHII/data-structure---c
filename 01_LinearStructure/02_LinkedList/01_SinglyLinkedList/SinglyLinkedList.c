#include"SinglyLinkedList.h"

List_t * Create()
{
	List_t * list = malloc(sizeof(List_t));

	list->head.next = NULL;
	list->num = 0;

	return list;
}

void Release(List_t * list)
{
	Node_t * p = &list->head;

	while(p->next)
	{
		Node_t * t = p->next;
		p->next = t->next;
		free(t);
	}

	free(list);
}

void head_insert(List_t * list , Element_t value)
{
	Node_t * p = &list->head;

	Node_t *new_node = malloc(sizeof(Node_t));
	new_node->next = NULL;
	new_node->value = value;

	new_node->next = p->next;
	p->next = new_node;

	list->num++;
}

void tail_insert(List_t * list , Element_t value)
{
	Node_t * p = &list->head;

	while(p->next)
	{
		p = p->next;
	}

	Node_t *new_node = malloc(sizeof(Node_t));
	new_node->next = NULL;
	new_node->value = value;

	p->next = new_node;

	list->num++;
}

void insert(List_t * list , int place , Element_t value)
{
	int index = place - 1;

	if(index < 0 || index > list->num) return ;

	Node_t * p = &list->head;

	for(int i = 0 ; i < index ; i++)
	{
		p = p->next;
	}

	Node_t *new_node = malloc(sizeof(Node_t));
	new_node->next = NULL;
	new_node->value = value;

	new_node->next = p->next;
	p->next = new_node;

	list->num++;
}

void Delete(List_t * list, Element_t value)
{
	Node_t * p = &list->head;

	while(p->next)
	{
		if(p->next->value == value) break;
		p = p->next;
	}

	if(p->next == NULL)
	{
		printf("删除元素不存在\n");
		return ;
	}

	Node_t * t = p->next;
	p->next = t->next;
	free(t);

	list->num--;
}