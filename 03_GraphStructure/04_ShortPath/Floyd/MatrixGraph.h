#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 20

#define INF 1e5

typedef struct {
	char * show;
	int index;
}Ver_t;

typedef struct {
	Ver_t ver[Max];
	int Edge[Max][Max];
	int numver;
}Graph_t;

Graph_t * Create(char * name[],int n);

void getedge(Graph_t * graph , int x , int y , int w);

void DFS(Graph_t * graph,int start);

void BFS(Graph_t * graph , int start);

