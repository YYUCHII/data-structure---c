#include"Kruskal.h"

Graph_t * Create(char * name[] , int n)
{
	Graph_t * graph = malloc(sizeof(Graph_t));

	graph->numedge = 0;
	graph->numver = n;

	for(int i = 0 ; i < n;i++)
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

void getedge(Graph_t * graph,int x,int y , int w)
{
	if(x == y) return ;

	graph->Edge[x][y] = w;
	graph->Edge[y][x] = w;

	graph->numedge++;
}

EdgeSet_t * initEdgeSet(Graph_t * graph)
{
	EdgeSet_t * edgeset = malloc(sizeof(EdgeSet_t)*graph->numedge);

	int count = 0;

	for(int i = 0 ; i < graph->numver ; i++)
	{
		for(int j = i ; j < graph->numver ;j++)
		{
			if(graph->Edge[i][j] != INF)
			{
				edgeset[count].start = i;
				edgeset[count].end = j;
				edgeset[count++].weight = graph->Edge[i][j];
			}
		}
	}

	for(int i = 0 ; i < graph->numedge- 1; i++)
	{
		for(int j = 0 ; j < graph->numedge - 1- i ;j++)
		{
			if(edgeset[j].weight > edgeset[j+1].weight)
			{
				EdgeSet_t temp = edgeset[j];
				edgeset[j] = edgeset[j+1];
				edgeset[j+1] = temp;
			}
		}
	}

	return edgeset;
}

void Release(Graph_t * graph,EdgeSet_t * edgeset)
{
	free(graph);
	free(edgeset);
}

int getRoot(int * QU , int index)
{
	while(index != QU[index])
	{
		index = QU[index];
	}

	return index;
}

int kruskal(Graph_t * graph,EdgeSet_t * edgeset)
{
	int sum = 0;

	int QU[graph->numver];
	for(int i = 0 ; i < graph->numver ; i++) QU[i] = i;

	for(int i = 0 ; i < graph->numedge ; i++)
	{
		int startroot = getRoot(QU, edgeset[i].start);
		int endroot = getRoot(QU, edgeset[i].end);

		if(startroot != endroot)
		{
			sum += edgeset[i].weight;
			QU[startroot] = endroot;
		}
	}

	return sum;
}