#include"HuffmanTree.h"

void FindTwoMin(Huffman_t * tree, int * m1, int* m2, int range)
{
	int tempmin = 0;

	for(int i = 1 ; i <= range ; i++)
	{
		if(tree[i].parent == 0)
		{
			tempmin = i;
			break;
		}
	}

	for(int i = 1 ; i <= range  ;i++)
	{
		if(tree[i].parent == 0 && tree[i].weight < tree[tempmin].weight) tempmin = i;
	}

	*m1 = tempmin;

	for(int i = 1 ; i<= range ; i++)
	{
		if(tree[i].parent == 0 && i != tempmin)
		{
			tempmin = i;
			break;
		}
	}

	for(int i = 1 ; i <= range ; i++)
	{
		if(tree[i].parent == 0 && tree[i].weight < tree[tempmin].weight && tree[i].weight != tree[*m1].weight) tempmin = i;
	}

	*m2 = tempmin;

}


Huffman_t * Create(int * weight,int n )
{
	Huffman_t * tree = malloc(sizeof(Huffman_t)*2*n);

	memset(tree,0,sizeof(Huffman_t)*2*n);

	for(int i = 1; i <= n ; i++ )
	{
		//因为tree是从1开始，但是weight的索引是从0开始
		tree[i].weight = weight[i-1];
	}

	int m1;
	int m2;

	for(int i = n + 1; i < 2*n ; i++)
	{
		FindTwoMin(tree, &m1, &m2, i-1);

		tree[m1].parent = i;
		tree[m2].parent = i;
		tree[i].weight = tree[m1].weight + tree[m2].weight;
		tree[i].lchild = m1;
		tree[i].rchild = m2;
	}

	return tree;
}

void Release(Huffman_t * tree)
{
	free(tree);
}

Code * createCode(Huffman_t * tree, int n)
{
	char * temp = malloc(sizeof(char)*n);

	Code * codes = malloc(sizeof(Code)*2*n);
	memset(codes,0,sizeof(Code)*2*n);

	int start ;

	int parent ;

	int child;

	for(int i = 1 ; i <= 2 * n -1 ; i++)
	{
		start = n - 1;
		temp[start] = '\0';

		parent = tree[i].parent;
		child = i;

		while(parent != 0)
		{
			if(tree[parent].lchild == child) temp[--start] = '0';
			else temp[--start] = '1';

			child = parent;
			parent = tree[parent].parent;
		}

		//因为codes是从0号索引开始放
		codes[i-1] = malloc(sizeof(char)*(n-1-start+1));
		strcpy(codes[i-1],&temp[start]);
	}

	return codes;
}

void releaseCode(Code*codes,int n)
{
	for(int i = 0 ; i < 2 * n-1 ; i++)
	{
		free(codes[i]);
	}
	free(codes);
}