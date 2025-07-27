#include"DoubleCircularLinkedList.h"

List_t * Create()
{
	List_t *list = malloc(sizeof(List_t));

	list->head.next = list->head.prev = &list->head;

	list->num = 0;

	return list;
}

void del(Node_t * prev , Node_t * node, Node_t * next)
{
	next->prev = prev;
	prev->next = next;
	free(node);
}

void Release(List_t * list)
{
	//1,站在头节点，删后一个节点
	Node_t * p = &list->head;

	while(p->next != &list->head)
	{
		del(p,p->next,p->next->next);
	}
	
	free(list);

	//2，站在第一个节点，删这个节点
	/*
	Node_t * p = list->head.next;

	while(p != &list->head)
	{
		del(p->prev,p,p->next);
		p = list->head.next;
	}

	free(list);
	*/
}

void addbase(Node_t * prev , Node_t * node , Node_t * next)
{
	next->prev = node;
	node->next = next;
	node->prev = prev;
	prev->next = node;
}

Node_t * createNode(Element_t value)
{
	Node_t * node = malloc(sizeof(Node_t));

	node->value = value;

	return node;
}

void head_insert(List_t *list, Element_t value)
{
	Node_t * new_node = createNode(value);

	addbase(&list->head,new_node,list->head.next);

	list->num++;
}

void tail_insert(List_t *list, Element_t value)
{
	Node_t * new_node = createNode(value);

	addbase(list->head.prev,new_node , &list->head);

	list->num++;
}

void Delete(List_t *list, Element_t value)
{
	//一次删一个
	Node_t * target = list->head.next;

	while(target != &list->head)
	{
		if(target->value == value)
		{
			del(target->prev,target,target->next);
			list->num--;
			return;
		}
		target = target->next;
	}

	if(target == &list->head)
	{
		printf("no find\n");
		return;
	}

}