#include"QuickFindSet.h"

int main()
{
	//只能char * data = "abcd";
	
	char data[6] = {'a','b','c','d','e','f'};

	QFSet_t * set = Create(6, data);

	Union(set, 'a', 'c');

	if(Find(set, 'a', 'c'))
	{
		printf("yes");
	}

	Release(set);
}