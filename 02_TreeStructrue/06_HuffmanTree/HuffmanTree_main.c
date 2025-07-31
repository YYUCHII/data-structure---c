#include"HuffmanTree.h"

int main()
{
	int weight[5] = {1,2,3,4,5,};
	Huffman_t * tree = Create(weight, 5);

	for(int i = 1 ; i < 10 ; i++)
	{
		printf("index = %d\t weight = %d\tparent = %d\tlchild = %d\trchild = %d\n",i,tree[i].weight,tree[i].parent,tree[i].lchild,tree[i].rchild);

	}

	char ** codes = createCode(tree, 5);

	for(int i = 0 ; i < 9 ; i++)
	{
		printf("%s\n",codes[i]);
	}

	releaseCode(codes, 5);
	Release(tree);
	
}