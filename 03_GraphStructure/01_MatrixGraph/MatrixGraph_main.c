#include"MatrixGraph.h"

int main()
{
		char* name[] = { "V1","V2","V3","V4","V5","V6","V7","V8" };
	
		Graph_t * graph = Create(name, 8);

		getedge(graph, 0, 1, 1);
		getedge(graph, 0, 2, 1);
		getedge(graph, 1, 3, 1);
		getedge(graph, 1, 4, 1);
		getedge(graph, 2, 5, 1);
		getedge(graph, 2, 6, 1);
		getedge(graph, 3, 7, 1);
		getedge(graph, 4, 7, 1);
		getedge(graph, 5, 6, 1);


		DFS(graph, 0);
		printf("\n");
		BFS(graph, 0);

	
}