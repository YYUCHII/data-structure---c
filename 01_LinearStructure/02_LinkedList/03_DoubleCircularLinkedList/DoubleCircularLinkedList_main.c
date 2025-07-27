#include"DoubleCircularLinkedList.h"

void Show(List_t * list)
{
	Node_t * p = list->head.next;

	while(p != &list->head)
	{
		printf("%d\t",p->value);
		p = p->next;
	}
}

int main()
{
	List_t * list = Create();

	head_insert(list, 3);
	head_insert(list, 4);

	tail_insert(list, 2);
	tail_insert(list, 1);

	Delete(list, 1);

	printf("num = %d\n",list->num);
	Show(list);

	Release(list);
}