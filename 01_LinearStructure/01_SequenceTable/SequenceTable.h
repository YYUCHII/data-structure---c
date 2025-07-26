#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Element_t;

typedef struct{
	Element_t * data;
	int pos;
	int capacity;
}SequenceTable_t;

SequenceTable_t * Create(int n);

void Release(SequenceTable_t*table);

void Push(SequenceTable_t * table,Element_t value);

void Insert(SequenceTable_t * table,int place,Element_t value);

void Delete(SequenceTable_t * table,Element_t value);

void Find(SequenceTable_t * table,Element_t value);
