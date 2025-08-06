#include"HeapSort.h"

Heap * Create(int n)
{
	Heap * heap = malloc(sizeof(Heap));

	heap->table = malloc(sizeof(int)*(n+1));
	heap->num = 0;

	return heap;
}

void Release(Heap *heap)
{
	free(heap->table);
	free(heap);
}

//分界线

void ShiftUP(Heap * heap , int k)
{
	while(k/2 != 0 && heap->table[k/2] > heap->table[k])
	{
		int temp = heap->table[k/2];
		heap->table[k/2] = heap->table[k];
		heap->table[k] = temp;
		k /= 2;
	}
}

void popHeap(Heap * heap,int value)
{
	heap->num++;
	heap->table[heap->num] =value;

	ShiftUP(heap, heap->num);
}

//分界线

void ShiftDown(Heap * heap , int k)
{
	while(2*k <= heap->num )
	{
		int index = 2*k;

		if(2*k + 1 <= heap->num && heap->table[2*k+1] < heap->table[2*k])
		{
			index = 2*k+1;
		}

		if(heap->table[index] > heap->table[k]) break;

		int temp = heap->table[index];
		heap->table[index] = heap->table[k];
		heap->table[k] = temp;
		k = index;
	}
}

int pushHeap(Heap * heap)
{
	int res = heap->table[1];
	heap->table[1] = heap->table[heap->num];
	heap->num--;

	ShiftDown(heap, 1);

	return res;

}