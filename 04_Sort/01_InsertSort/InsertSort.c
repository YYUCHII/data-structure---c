#include"InsertSort.h"

void InsertSequence(int * table,int n)
{
	for(int i = 1 ; i < n ; i++)
	{
		int target = table[i];
		int t = i - 1;

		while(t != -1 && table[t] > target)
		{
			table[t+1] = table[t];
			t--;
		}

		table[t+1] =target;

	}
}

void InsertList(List_t * list)
{
	if(list->head.next == NULL || list->head.next->next == NULL) return ;

	Node_t * p = &list->head;
	Node_t * temp = p->next->next;
	p->next->next = NULL;

	while(temp != NULL)
	{
		Node_t * temp1 = temp->next;

		while(p->next->key < temp->key)
		{
			p = p->next;
		}

		temp->next = p->next;
		p->next = temp;

		temp = temp1;
		p = &list->head;
	}
}
