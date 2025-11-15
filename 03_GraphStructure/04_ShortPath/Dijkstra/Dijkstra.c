#include"Dijkstra.h"

Graph_t * Create(char *name[],int n)
{
	Graph_t * graph = malloc(sizeof(Graph_t));

	graph->numver = n;

	for(int i = 0 ; i < n ;i++)
	{
		graph->Ver[i].show = name[i];
		graph->Ver[i].index = i;

		for(int j = 0 ;  j < n ;j++)
		{
			graph->Edge[i][j] = INF;
		}
	}

	return graph;
}

void getedge(Graph_t * graph,int x,int y , int w)
{
	if(x == y) return;

	graph->Edge[x][y] = w;
	graph->Edge[y][x] = w;
}

Path_t * CreatePath(int n)
{
	Path_t * path = malloc(sizeof(Path_t) * n);

	for(int i = 0 ; i < n;i++)
	{
		path->weight[i] = INF;
		path->from[i] = -1;
	}

	return path;
}

void Release(Graph_t * graph, Path_t * path)
{
	free(graph);
	free(path);
}

void Dijkstra(Graph_t * graph,int startV,Path_t * path)
{
	int visit[Max] = {0};

	for(int i = 0 ; i < graph->numver ; i++)
	{
		if(graph->Edge[startV][i] < path->weight[i])
		{
			path->weight[i] = graph->Edge[startV][i];
			path->from[i] = startV;
		}
	}

	path->weight[startV] = 0;
	visit[startV] = 1;

	for(int i = 0 ; i < graph->numver- 1; i++)
	{
		int min = INF;
		int min_index = -1;

		for(int j = 0 ; j < graph->numver  ; j++)
		{
			if(visit[j] == 0 && path->weight[j] < min)
			{
				min = path->weight[j];
				min_index = j;
			}
		}

		visit[min_index] = 1;

		for(int j = 0 ; j < graph->numver ; j++)
		{
			if(visit[j] == 0 && graph->Edge[min_index][j] + path->weight[min_index] < path->weight[j])
			{
				path->weight[j] = graph->Edge[min_index][j] + path->weight[min_index];
				path->from[j] = min_index;
			}
		}
	}
}

void ShowPath(Graph_t * graph , int target , Path_t * path)
{
	int stack[Max];
	int top = 0;

	int temp = target;

	while(temp != -1)
	{
		stack[top] = temp;
		top++;
		temp = path->from[temp];
	}

	while(top != 0)
	{
		top--;
		printf("%s\t",graph->Ver[stack[top]].show);
	}

	printf("\n%d\t",path->weight[target]);
}