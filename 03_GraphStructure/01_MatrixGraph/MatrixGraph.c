#include"MatrixGraph.h"

Graph_t * Create(char * name[],int n)
{
	Graph_t * graph = malloc(sizeof(Graph_t));

	graph->numver = n;

	for(int i = 0 ; i < n ;i++)
	{
		graph->ver[i].show = name[i];
		graph->ver[i].index = i;

		for(int j = 0 ; j < n ;j++)
		{
			graph->Edge[i][j] = INF;
		}
	}

	return graph;
}

void getedge(Graph_t * graph , int x , int y , int w)
{
	if(x == y) return ;
	graph->Edge[x][y] = w;
	graph->Edge[y][x] = w;
}

static int Dlook[Max] = {0};

void DFS(Graph_t * graph,int start)
{
	printf("%s\t",graph->ver[start].show);
	Dlook[start] = 1;

	for(int i = 0 ; i < graph->numver ; i++)
	{
		if(graph->Edge[start][i] < INF && Dlook[i] == 0) DFS(graph,i);
	}
}

static int Blook[Max] = {0};

void BFS(Graph_t * graph , int start)
{
	int queue[Max];
	int front = 0;
	int rear = 0;

	rear = (rear + 1) % Max;
	queue[rear] = start;
	Blook[start] = 1;

	while(front != rear)
	{
		front = (front + 1)%Max;
		printf("%s\t",graph->ver[queue[front]].show);

		for(int i = 0 ; i < graph->numver  ;i++)
		{
			if(graph->Edge[queue[front]][i] < INF && Blook[i] == 0)
			{
				rear = (rear + 1) % Max;
				queue[rear] = i;
				Blook[i] = 1;
			}
		}
	}

}