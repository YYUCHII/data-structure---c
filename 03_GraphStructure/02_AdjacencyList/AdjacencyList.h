#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _edge{
	int index;
	int w;
	struct _edge * next;
}Edge_t;

typedef struct {
	int index;
	char * show;
	Edge_t * next;
}Ver_t;

typedef struct {
	Ver_t *ver;
	int numver;
}Graph_t;

Graph_t * Create(char *name[],int n);

void getedge(Graph_t * graph,int x , int y ,int w);

void DFS(Graph_t * graph,int start);

void BFS(Graph_t * graph,int start);