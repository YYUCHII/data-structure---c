#include"Dijkstra.h"

int main()
{
	char* name[] = { "A","B","C","D","E","F","G" };
	Graph_t * graph = Create(name, 7);

	Path_t * path = CreatePath(7);

	getedge(graph, 0, 1, 4);
	getedge(graph, 0, 2, 6);
	getedge(graph, 0, 3, 6);
	getedge(graph, 1, 4, 7);
	getedge(graph, 1, 2, 1);
	getedge(graph, 2, 4, 6);
	getedge(graph, 2, 5, 4);
	getedge(graph, 3, 2, 2);
	getedge(graph, 3, 5, 5);
	getedge(graph, 4, 6, 6);
	getedge(graph, 5, 4, 1);
	getedge(graph, 5, 6, 8);

	Dijkstra(graph,0,path);

	ShowPath(graph,2, path);

	Release(graph, path);

}