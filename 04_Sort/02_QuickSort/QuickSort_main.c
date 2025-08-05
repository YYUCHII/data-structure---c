#include"QuickSort.h"

int main()
{
	int table[4] = {4,3,2,1};

	QuickSort(table);

	for(int i = 0 ; i < 4 ; i++)
	{
		printf("%d\t",table[i]);
	}

	return 0;
}