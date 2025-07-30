#include"QuickUnionSet.h"

int main()
{
	char data[3] = {'a','b','c'};

	QUSet_t * set = Create(3, data);

	Union(set, 'a', 'c');

	if(Find(set, 'a', 'c'))
	{
		printf("yes\n");
	}

	Release(set);
}