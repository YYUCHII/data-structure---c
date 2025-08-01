#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 20
#define INF 1e5

typedef struct {
	char * show;
	int  index;
}Ver_t;

typedef struct{
	Ver_t Ver[Max];
	int Edge[Max][Max];
	int numver;
	int numedge;
}Graph_t ;

typedef struct{
	int start;
	int end;
	int weight;
}EdgeSet_t;

Graph_t * Create(char * name[] , int n);

void getedge(Graph_t * graph,int x,int y , int w);

EdgeSet_t * initEdgeSet(Graph_t * graph);

void Release(Graph_t * graph,EdgeSet_t * edgeset);

int kruskal(Graph_t * graph,EdgeSet_t * edgeset);
