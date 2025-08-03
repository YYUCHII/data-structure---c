#include"TopologicalSort.h"

Graph_t * Create(char * name[] , int n)
{
	Graph_t * graph = malloc(sizeof(Graph_t));
	
	graph->Ver = malloc(sizeof(Ver_t)*n);
	graph->numver = n;

	for(int i = 0 ; i < n ; i++)
	{
		graph->Ver[i].show = name[i];
		graph->Ver[i].index = i;
		graph->Ver[i].next = NULL;
	}

	return graph;
}

void Release(Graph_t *graph)
{
	for(int i = 0 ; i < graph->numver ; i++)
	{
		Ver_t * p = &graph->Ver[i];

		while(p->next)
		{
			Node_t * t = p->next;
			p->next = t->next;
			free(t);
		}
	}

	free(graph->Ver);
	free(graph);
}

void getedge(Graph_t *graph,int x,int y)
{
	Node_t * node = malloc(sizeof(Node_t));
	
	node->index = y;

	node->next = graph->Ver[x].next;
	graph->Ver[x].next = node;
}

int TopologicalSort(Graph_t * graph)
{
	int stack[20] ;
	int top = 0;

	int InDegree[20] = {0};

	int count = 0;

	//初始化InDegree数组
	for(int i = 0 ; i < graph->numver ; i++)
	{
		Node_t * p = graph->Ver[i].next;

		while(p)
		{
			InDegree[p->index]++;
			p = p->next;
		}
	}

	//初始化stack
	for(int i = 0 ; i < graph->numver ; i++)
	{
		if(InDegree[i] == 0)
		{
			stack[top++] = i;
		}
	}

	while(top != 0)
	{
		int target = stack[--top];
		printf("%s\t",graph->Ver[target].show);
		count++;

		Node_t * t = graph->Ver[target].next;
		while(t)
		{
			InDegree[t->index]--;
			if(InDegree[t->index] == 0)
			{
				stack[top++] = t->index;
			}
			t = t->next;
		}
	}

	if(count == graph->numver) return 1;
	return -1;
}
