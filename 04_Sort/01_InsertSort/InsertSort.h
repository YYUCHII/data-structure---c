#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1，数组排序
void InsertSequence(int * table,int n);

//2，链表排序
typedef struct _node{
	int key;
	struct _node * next;
}Node_t;

typedef struct {
	Node_t head;
	int num;
}List_t;

void InsertList(List_t * list);