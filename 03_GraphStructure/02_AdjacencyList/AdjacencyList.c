#include"AdjacencyList.h"

Graph_t * Create(char *name[],int n)
{
	Graph_t * graph = malloc(sizeof(Graph_t));

	graph->numver = n;

	graph->ver = malloc(sizeof(Ver_t)*n);

	for(int i = 0 ; i < n ; i++)
	{
		graph->ver[i].show = name[i];
		graph->ver[i].index = i;
		graph->ver[i].next = NULL;
	}
	return graph;
}

void getedge(Graph_t * graph,int x , int y ,int w)
{
	Edge_t * edge = malloc(sizeof(Edge_t));
	edge->index = y;
	edge->w = w;

	edge->next = graph->ver[x].next;
	graph->ver[x].next = edge;

}

static int Dlook[20] = {0};

void DFS(Graph_t * graph,int start)
{
	printf("%s\t",graph->ver[start].show);
	Dlook[start] = 1;

	Edge_t * p = graph->ver[start].next;

	while(p)
	{
		if(Dlook[p->index] == 0) DFS(graph,p->index);
		p = p->next;
	}
}

static int Blook[20] = {0};

void BFS(Graph_t * graph,int start)
{
	int queue[20];
	int front = 0;
	int rear = 0;

	rear = (rear + 1)% 20;
	queue[rear] = start;
	Blook[start] = 1;

	while(front != rear)
	{
		front = (front + 1)%20;
		printf("%s\t",graph->ver[queue[front]].show);

		Edge_t * p = graph->ver[queue[front]].next;

		while(p)
		{
			if(Blook[p->index] == 0)
			{
				rear = (rear + 1)%20;
				queue[rear] = p->index;
				Blook[p->index] = 1;
			}
			p = p->next;
		}
	}
}