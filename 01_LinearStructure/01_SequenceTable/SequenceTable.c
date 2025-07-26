#include"SequenceTable.h"

SequenceTable_t * Create(int n)
{
	SequenceTable_t * table = malloc(sizeof(SequenceTable_t));

	table->data = malloc(sizeof(Element_t)*n);
	table->pos = 0;
	table->capacity = n;

	return table;
}

void Release(SequenceTable_t*table)
{
	free(table->data);
	free(table);
}

void Largen(SequenceTable_t * table)
{
	Element_t * temp = malloc(sizeof(Element_t)*table->capacity*2);

	for(int i = 0 ; i < table->capacity ; i++) temp[i] = table->data[i];

	free(table->data);
	table->data = temp;

	table->capacity *= 2;
}

void Push(SequenceTable_t * table,Element_t value)
{
	if(table->pos == table->capacity) Largen(table);

	table->data[table->pos] = value;
	table->pos++;
}

void Insert(SequenceTable_t * table,int place,Element_t value)
{
	if(table->pos == table->capacity) Largen(table);

	int index = place - 1;

	if(index < 0 || index > table->pos)
	{
		printf("无效插入\n");
		return ;
	}

	for(int i = table->pos - 1 ; i >= index ; i--) table->data[i+1] = table->data[i];

	table->data[index] = value;

	table->pos++;
}

void Delete(SequenceTable_t * table,Element_t value)
{
	int target_index = -1;

	for(int i = 0 ; i < table->pos ; i++)
	{
		if(table->data[i] == value)
		{
			target_index = i;
			break;
		}
	}

	if(target_index == -1) printf("删除无效，因为元素不存在\n");

	for(int i = target_index ; i < table->pos ; i++) table->data[i] = table->data[i+1];

	table->pos--;
}

void Find(SequenceTable_t * table,Element_t value)
{
	for(int i = 0 ; i < table->pos ; i++)
	{
		if(table->data[i] == value) 
		{
			printf("Find!索引为：%d\n",i);
			return;
		}
	}

	printf("no find\n");
}
