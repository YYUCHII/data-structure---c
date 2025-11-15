#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 20
#define INF 1e5

typedef struct{
	char * show;
	int index;
}Ver_t;

typedef struct{
	Ver_t Ver[Max];
	int Edge[Max][Max];
	int numver;
}Graph_t;

//将距离，路径包装
typedef struct{
	int weight[Max];
	int from[Max];
}Path_t;

Graph_t * Create(char *name[],int n);

void getedge(Graph_t * graph,int x,int y , int w);

Path_t * CreatePath(int n);

void Release(Graph_t * graph, Path_t * path);

void Dijkstra(Graph_t * graph,int startV,Path_t * path);

void ShowPath(Graph_t * graph , int target , Path_t * path);