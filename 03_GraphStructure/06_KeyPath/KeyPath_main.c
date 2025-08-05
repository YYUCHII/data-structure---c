#include"KeyPath.h"

int main()
{
	char *names[] = {"V0", "V1", "V2", "V3", "V4", "V5", "V6", "V7","V8"};
		
	Graph_t *graph = Create(names,9);
	
	getedge(graph, 0, 1, 6);
	getedge(graph, 0, 2, 4);
	getedge(graph, 0, 3, 5);
	getedge(graph, 1, 4, 1);
	getedge(graph, 2, 4, 1);
	getedge(graph, 3, 5, 2);
	getedge(graph, 4, 6, 9);
	getedge(graph, 4, 7, 7);
	getedge(graph, 5, 7, 4);
	getedge(graph, 6, 8, 2);
	getedge(graph, 7, 8, 4);
	
	KeyPath(graph);

	Release(graph);
	return 0;

}