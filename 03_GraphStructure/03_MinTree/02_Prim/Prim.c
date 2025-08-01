#include"Prim.h"

Graph_t * Create(char * name[],int n)
{
	Graph_t * graph = malloc(sizeof(Graph_t));

	graph->numver = n;
	graph->numedge = 0;

	for(int i = 0 ; i < n ; i++)
	{
		graph->Ver[i].show = name[i];
		graph->Ver[i].index = i;

		for(int j = 0 ; j < n ;j++)
		{
			graph->Edge[i][j] = INF;
		}
	}

	return graph;
}

void getedge(Graph_t * graph,int x,int y ,int w)
{
	if(x == y) return ;
	graph->Edge[x][y] = w;
	graph->Edge[y][x] = w;
	graph->numedge++;
}

void Release(Graph_t *graph)
{
	free(graph);
}

int Prim(Graph_t * graph , int startV)
{
	int * weight = malloc(sizeof(int)*graph->numver);
	int * visit = malloc(sizeof(int)*graph->numver);
	int * from = malloc(sizeof(int)*graph->numver);

	for(int i = 0 ; i < graph->numver ; i++)
	{
		weight[i] = INF;
		visit[i] = 0;
		from[i] = -1;
	}

	for(int i = 0 ; i < graph->numver ; i++)
	{
		if(graph->Edge[startV][i] < INF)
		{
			weight[i] = graph->Edge[startV][i];
			from[i] = startV;
		}
	}

	visit[startV] = 1;

	int sum = 0;

	for(int i = 0 ; i < graph->numver-1 ;i++)
	{
		int min = INF;
		int min_index; 

		for(int j = 0 ; j < graph->numver  ;j++)
		{
			if(visit[j] == 0 && weight[j] < min)
			{
				min = weight[j];
				min_index = j;
			}
		}

		sum += min;
		visit[min_index] = 1;

		for(int j =  0 ; j < graph->numver ; j++)
		{
			if(visit[j] == 0 && graph->Edge[min_index][j] < weight[j])
			{
				weight[j] = graph->Edge[min_index][j];
				from[j] = min_index;
			}
		}
	}

	return sum;
}