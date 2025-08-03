#include"TopologicalSort.h"

int main()
{
	char* name[] = { "0","1","2"};

	Graph_t* graph = Create(name,3);
	
	getedge(graph, 0, 1);
	getedge(graph, 0, 2);
	
	printf("\n%d\n",TopologicalSort(graph));

	Release(graph);
}