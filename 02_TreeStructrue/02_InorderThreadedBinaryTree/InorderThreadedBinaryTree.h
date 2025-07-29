#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

typedef int Element_t ;

typedef struct _node{
	Element_t value;
	struct _node * left;
	struct _node * right;
	int Lflag;
	int Rflag;
}Node_t ;

typedef struct{
	Node_t * root;
}Tree_t ;

Node_t * createNode(Element_t value);

void conbination(Node_t *left, Node_t *node, Node_t *right);

void Release(Tree_t * tree);

Tree_t * createTree(Node_t * root);

void InorderThreading(Tree_t * tree);

void InorderThreadedSearch(Tree_t * tree);

