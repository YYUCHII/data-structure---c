#include"AdjacencyList.h"

int main()
{
	char* name[] = { "A","B","C","D","E" };

	Graph_t* graph = Create(name, 6);

	

	getedge(graph, 0, 4, 1);
	getedge(graph, 0, 3, 1);
	getedge(graph, 0, 1, 1);
	getedge(graph, 1, 4, 1);
	getedge(graph, 1, 2, 1);
	getedge(graph, 2, 0, 1);
	getedge(graph, 3, 2, 1);
		
	DFS(graph, 0);
	printf("\n");
		
	BFS(graph, 0);
}