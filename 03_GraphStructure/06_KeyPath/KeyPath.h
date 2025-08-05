#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	int index;
	int weight;
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

void getedge(Graph_t *graph,int x,int y,int w);

//我选择输出关键路径的长度
void KeyPath(Graph_t * graph);