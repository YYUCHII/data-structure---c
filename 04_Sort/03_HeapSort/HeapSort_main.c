#include"HeapSort.h"

int main()
{
	Heap * heap = Create(5);

	popHeap(heap, 4);
	popHeap(heap,5);
	popHeap(heap,2);
	popHeap(heap,1);
	popHeap(heap,3);

	for(int i = 0 ; i < 5 ; i++)
	{
		printf("%d\t",pushHeap(heap));
	}


	Release(heap);

}