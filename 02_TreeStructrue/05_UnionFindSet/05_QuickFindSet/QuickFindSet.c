#include"QuickFindSet.h"

QFSet_t * Create(int n , Element_t * source)
{
	QFSet_t * set = malloc(sizeof(QFSet_t));

	set->data = malloc(sizeof(Element_t)*n);
	set->groupID = malloc(sizeof(int)*n);
	set->n = n;

	for(int i = 0 ; i < n ;i++)
	{
		set->data[i] = source[i];
		set->groupID[i] = i;
	}

	return set;
}

void Release(QFSet_t * set)
{
	free(set->groupID);
	free(set->data);
	free(set);
}

//分割线
//求元素的本质索引
int getindex(QFSet_t * set , Element_t e)
{
	for(int i = 0 ; i < set->n ; i++)
	{
		if(set->data[i] == e) return i;
	}

	return -1;
}

//分割线

int Find(QFSet_t * set,Element_t v1,Element_t v2)
{
	int index1 = getindex(set, v1);
	int index2 = getindex(set, v2);

	if(set->groupID[index1] == set->groupID[index2]) return 1;
	return -1;
}

//分割线
void Union(QFSet_t * set , Element_t v1, Element_t v2)
{
	int index1 = getindex(set, v1);
	int index2 = getindex(set, v2);

	int v1_groupID = set->groupID[index1];

	for(int i = 0 ; i <set->n ; i++)
	{
		if(set->groupID[i] == v1_groupID) set->groupID[i] = set->groupID[index2];
	}
}
