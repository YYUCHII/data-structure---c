#include"MergeSort.h"

int main()
{
	int table[5] = {3,2,4,5,1};

	printf("1\n");

	MergeSort(table,5);

	for(int i= 0 ; i < 5 ; i++)
	{
		printf("%d\t",table[i]);
	}

	return 0;
}