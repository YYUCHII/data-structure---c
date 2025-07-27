#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Element_t;

typedef struct _node{
	Element_t value;
	struct _node * next;
}Node_t;

typedef struct{
	Node_t head;
	int num;
}List_t;

List_t * Create();

void Release(List_t * list);

void head_insert(List_t * list , Element_t value);

void tail_insert(List_t * list , Element_t value);

void insert(List_t * list , int place , Element_t value);

void Delete(List_t * list, Element_t value);
