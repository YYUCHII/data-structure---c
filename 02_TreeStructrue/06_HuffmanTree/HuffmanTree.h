#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//************************最重要的理解 ************************************************/
//如果开始有n个节点，构建哈夫曼树后，会有2*n-1个节点，那么从1号索引开始，就需要2*n个空间

typedef struct{
	int weight;
	int parent;
	int lchild;
	int rchild;
}Huffman_t;

Huffman_t * Create(int * weight,int n );

void Release(Huffman_t * tree);

typedef char * Code;

Code * createCode(Huffman_t * tree, int n);

void releaseCode(Code*codes,int n);

