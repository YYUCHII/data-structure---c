#include"LinkedList.h"

void Show(List_t * list)
{
	Node_t * p = &list->head;

	while(p->next)
	{
		printf("%d\t",p->next->value);
		p = p->next;
	}
}

int main()
{
	List_t * list = Create();

	head_insert(list, 1);

	tail_insert(list, 3);

	head_insert(list, 2);
	
	tail_insert(list, 4);

	insert(list, 3, 5);

	Delete(list, 5);

	printf("num = %d\n",list->num);
	Show(list);


	Release(list);
}