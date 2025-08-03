#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	int index;
	struct _node * next;
}Node_t;

typedef struct {
	char * show;
	int index;
	Node_t * next;
}Ver_t;

typedef struct{
	Ver_t * Ver;
	int numver;
}Graph_t;

Graph_t * Create(char * name[] , int n);

void Release(Graph_t *graph);

void getedge(Graph_t *graph,int x,int y);

int TopologicalSort(Graph_t * graph);