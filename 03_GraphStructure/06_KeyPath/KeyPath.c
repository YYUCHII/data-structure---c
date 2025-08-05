#include"KeyPath.h"

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

void getedge(Graph_t *graph,int x,int y,int w)
{
	Ver_t * p = &graph->Ver[x];

	Node_t * node = malloc(sizeof(Node_t));
	node->index = y;
	node->weight = w;

	node->next = p->next;
	p->next = node;
}

void initELTV(Graph_t * graph,int * ETV,int * LTV)
{
	int stack[20];
	int top = -1;

	int InDegree[20] = {0};
	
	//记录从stack里出来的节点的索引，为了LTV
	int LTVtool[20];
	int index = 0;

	for(int i = 0 ; i < graph->numver ; i++)
	{
		Node_t * p = graph->Ver[i].next;

		while(p)
		{
			InDegree[p->index]++;
			p = p->next;
		}
	}

	for(int i = 0 ; i < graph->numver;i++)
	{
		if(InDegree[i] == 0)
		{
			stack[++top] = i;
		}
	}

	while(top != -1)
	{
		int top_index = stack[top--];
		LTVtool[index++] = top_index;

		Node_t * t = graph->Ver[top_index].next;

		while(t)
		{
			InDegree[t->index]--;
			if(InDegree[t->index] == 0)
			{
				stack[++top] = t->index;
			}
			if(ETV[top_index] + t->weight > ETV[t->index])
			{
				ETV[t->index] = ETV[top_index] + t->weight;
			}
			t = t->next;
		}
	}

	//ETV完成，接下来是LTV

	//将LTV初始化为最大值
	int max = ETV[--index];
	memset(LTV,max,sizeof(int)*graph->numver);

	while(index != 0)
	{
		int t_index = LTVtool[--index];
		//取倒数第二个节点,因为第一个一定是最大值
		Node_t * temp = graph->Ver[t_index].next;

		while(temp)
		{
			if(LTV[temp->index] - temp->weight < LTV[t_index])
			{
				LTV[t_index] = LTV[temp->index] - temp->weight;
			}
			temp = temp->next;
		}
	}
}

void KeyPath(Graph_t * graph)
{
	//最重要的就是ETV和LTV，所有用拓扑排序求这两个
	int * ETV = malloc(sizeof(int)*graph->numver);
	int * LTV = malloc(sizeof(int)*graph->numver);
	memset(ETV,0,sizeof(int)*graph->numver);
	memset(LTV,0,sizeof(int)*graph->numver);

	initELTV(graph, ETV, LTV);

	printf("keypath num = %d\n",ETV[graph->numver-1]);

	for(int i = 0 ;  i < graph->numver ; i++)
	{
		if(ETV[i] == LTV[i])
		{
			printf("%s\n",graph->Ver[ETV[i]].show);
		}
	}
}