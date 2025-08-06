#include"MergeSort.h"

void Merge(int * table, int left,int mid, int right)
{
	int n1 = mid-left;
	int n2 = right - mid;

	int* arr1 = malloc(sizeof(int)*n1);
	int * arr2 = malloc(sizeof(int)*n2);

	for(int i = 0 ; i < n1 ; i++) arr1[i] = table[left+i];
	for(int i = 0 ; i < n2 ; i++) arr2[i] = table[mid+i];

	int i = 0;
	int j = 0;
	int k = left;

	while(i < n1 && j < n2)
	{
		if(arr1[i] <= arr2[j]) table[k] = arr1[i++];
		else table[k] = arr2[j++];
		k++;
	}

	while(i < n1) table[k++] = arr1[i++];
	while(j < n2) table[k++] = arr2[j++];

	free(arr1);
	free(arr2);
}

void MergeSortTool(int * table, int left, int right)
{
	if(right - left <= 1) return ;

	int mid = (right + left) / 2;

	MergeSortTool(table, left, mid);
	MergeSortTool(table, mid, right);

	Merge(table,left,mid,right);
}


void MergeSort(int * table, int length)
{
	MergeSortTool(table, 0, length);
}