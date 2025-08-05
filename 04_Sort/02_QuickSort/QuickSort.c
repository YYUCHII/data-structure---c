#include"QuickSort.h"

//找奇点，递归
int findpivot(int * table, int startindex , int endindex)
{
	int mask = startindex;

	for(int i = startindex + 1; i < endindex ; i++)
	{
		if(table[i] < table[startindex])
		{
			mask++;
			int temp = table[mask];
			table[mask] = table[i];
			table[i] = temp;
		}
	}

	int temp = table[startindex];
	table[startindex] = table[mask];
	table[mask] = temp;

	return mask;
}

//左闭右开
void quicksortTool(int * table,int startindex,int endindex)
{
	if(startindex == endindex) return;

	int pivot = findpivot(table, startindex, endindex);

	quicksortTool(table, startindex, pivot);
	quicksortTool(table, pivot+1, endindex);
	
}

void QuickSort(int * table)
{
	//当数组作为函数参数传入时，数组名会退化为一个指针。只有在数组的声明域内，数组名才可以表示整个数组空间
	//所以sizeof(table)/sizeof(int)这样不行
	quicksortTool(table,0,4);
}