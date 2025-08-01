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
	int numedge;
}Graph_t;

Graph_t * Create(char * name[],int n);

void getedge(Graph_t * graph,int x,int y ,int w);

void Release(Graph_t *graph);

int Prim(Graph_t * graph , int startV);