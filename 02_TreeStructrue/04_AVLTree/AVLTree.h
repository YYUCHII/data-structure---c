#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

typedef int Element_t ;

typedef struct _node {
	Element_t value;
	struct _node * left;
	struct _node * right;
}Node_t ;

typedef struct{
	Node_t * root;
	int num;
}Tree_t ;

Tree_t * Create();

void Release(Tree_t *tree);

void Insert(Tree_t * tree, Element_t value);

void Delete(Tree_t * tree, Element_t value);

void InorderShow(Tree_t * tree);
