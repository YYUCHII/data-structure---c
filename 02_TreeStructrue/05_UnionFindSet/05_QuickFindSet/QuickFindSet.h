#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

typedef char Element_t ;

/*
	两个数组
	data    |  |   |   |   |  |  |
	groupID |  |   |   |   |  |  |
 */

typedef struct{
	Element_t * data;
	int * groupID;
	int n;
}QFSet_t;

//开辟空间的同时初始化
QFSet_t * Create(int n , Element_t * source);

void Release(QFSet_t * set);

int Find(QFSet_t * set,Element_t v1,Element_t v2);

void Union(QFSet_t * set , Element_t v1, Element_t v2);