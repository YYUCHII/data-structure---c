#include"SequenceTable.h"

int main()
{
	SequenceTable_t * table = Create(5);

	Push(table,1);
	Push(table,3);
	Insert(table,2,2);

	for(int i = 0 ; i < 3 ;i++)
	{
		Push(table,i+4);
	}

	Delete(table,3);

	for(int i = 0 ; i < table->pos ; i++)
	{
		printf("%d\t",table->data[i]);
	}



	Release(table);
}