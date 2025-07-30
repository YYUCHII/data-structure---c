#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

typedef char Element_t;

/*
	data      |	 |	|	|	|	|
	parentID  |	|	|	|	|	|
	size      |	|	|	|	|	|

 */

typedef struct{
	Element_t * data;
	int *parentID;
	int * size;
	int n;
}QUSet_t;

QUSet_t * Create(int n , Element_t * source);

void Release(QUSet_t * set);

int Find(QUSet_t * set,Element_t a , Element_t b);

void Union(QUSet_t * set, Element_t a , Element_t b);

