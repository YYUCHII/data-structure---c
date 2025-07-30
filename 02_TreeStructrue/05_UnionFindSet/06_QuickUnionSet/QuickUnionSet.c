#include"QuickUnionSet.h"

QUSet_t * Create(int n , Element_t * source)
{
	QUSet_t * set = malloc(sizeof(QUSet_t));

	set->data = malloc(sizeof(Element_t)*n);
	set->parentID = malloc(sizeof(int)*n);
	set->size = malloc(sizeof(int)*n);
	set->n = n;

	for(int i = 0 ; i< n ; i++)
	{
		set->data[i] = source[i];
		set->parentID[i] = i;
		set->size[i] = 1;
	}

	return set;
}

void Release(QUSet_t * set)
{
	free(set->data);
	free(set->parentID);
	free(set->size);
	free(set);
}

//分割线

int getRoot(QUSet_t * set, Element_t e)
{
	int index = 0;

	for(int i = 0 ; i < set->n ;i++)
	{
		if(set->data[i] == e)
		{
			index = i;
			break;
		}
	}

	while(set->parentID[index] != index)
	{
		index = set->parentID[index];
	}

	return index;
}

//分割线
int Find(QUSet_t * set,Element_t a , Element_t b)
{
	int aindex = getRoot(set, a);
	int bindex = getRoot(set, b);

	if(aindex == bindex) return 1;
	return -1;
}

//分割线

void Union(QUSet_t * set, Element_t a , Element_t b)
{
	int aindex = getRoot(set, a);
	int bindex = getRoot(set, b);

	int asize = set->size[aindex];
	int bsize = set->size[bindex];

	if(asize >= bsize)
	{
		set->parentID[bindex] = aindex;
		set->size[aindex] += set->size[bindex];
	}
	else 
	{
		set->parentID[aindex] = bindex;
		set->size[bindex] += set->size[aindex];
	}
}