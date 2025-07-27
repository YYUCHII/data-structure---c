#include"CircularLinkedList.h"

void Show(List_t * list)
{
	Node_t * p = &list->head;

	while(p->next != &list->head)
	{
		printf("%d\t",p->next->value);
		p = p->next;
	}
}

int main()
{
	List_t * list = Create();

	head_insert(list,1);
	head_insert(list,2);

	tail_insert(list,3);
	tail_insert(list,4);

	Delete(list, 1);

	Delete(list, 4);

	tail_insert(list, 3);

	printf("num = %d\n",list->num);
	Show(list);

	Release(list);
}