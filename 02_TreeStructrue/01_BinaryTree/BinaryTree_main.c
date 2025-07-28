#include"BinaryTree.h"

int main()
{
	Node_t * a = createNode(1);
	Node_t * b = createNode(2);
	Node_t * c = createNode(3);

	conbination(b, a, c);

	Tree_t * tree= createTree(a);
	
	RDFS(tree);
	printf("\n");

	BFS(tree);
	printf("\n");

	NRDFS(tree);
	printf("\n");

	Release(tree);
}