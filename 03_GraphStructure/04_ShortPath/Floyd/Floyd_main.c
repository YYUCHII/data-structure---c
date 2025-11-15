#include<stdio.h>
#include"MatrixGraph.h"

void edgecode(Graph_t * graph)
{
	for(int i = 0 ; i < graph->numver ; i++)
	{
		graph->Edge[i][i] = 0;
	}
}

//全局变量
static int dist[Max][Max];
static int path[Max][Max];

void Floyd(Graph_t * graph)
{
	//初始化dist和path
	for(int i = 0 ; i < graph->numver ; i++)
	{
		for(int j = 0 ; j< graph->numver ; j++)
		{
			//dist直接复制图
			dist[i][j] = graph->Edge[i][j];
			//path需要判断
			if(i != j && dist[i][j] < INF )
			{
				path[i][j] = i;
			}
			else path[i][j] = -1;
		}
	}

	//开始更新floyd
	for(int k = 0 ; k < graph->numver ;k++)//辅助节点，
	{
		for(int i = 0 ; i < graph->numver ; i++)//起点
		{
			for(int j = 0 ; j < graph->numver ; j++)//终点
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

int main()
{
	//初始化图，用了MatrixGraph
	char * Name[] = {"V0","V1","V2","V3"};
	Graph_t * graph = Create(Name, sizeof(Name)/sizeof(Name[0]));
	//处理对角线
	edgecode(graph);

	//建立边
	getedge(graph,0,1,1);
	getedge(graph,0,3,4);
	getedge(graph,1,2,9);
	getedge(graph,1,3,2);
	getedge(graph,2,0,3);
	getedge(graph,2,1,5);
	getedge(graph,2,3,8);
	getedge(graph,3,2,6);

	//建立图完毕
	Floyd(graph);

	for(int i = 0 ; i < graph->numver ; i++)
	{
		for(int j = 0 ; j < graph->numver ; j++)
		{
			printf("%d\t",dist[i][j]);
		}
		printf("\n"); 
	}


}