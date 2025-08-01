#include"Prim.h"

int main()
{
	char * name [] = {"v0","v1","v2","v3"};
	Graph_t * graph = Create(name, 4);

	getedge(graph,0,1,3);
	getedge(graph, 0, 2, 1);
	getedge(graph, 0, 3, 4);
	getedge(graph, 1, 2, 2);
	getedge(graph, 2, 3, 5);

	printf("%d\n",Prim(graph,0));

	Release(graph);
}