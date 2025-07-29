#include"InorderThreadedBinaryTree.h"

int main()
{
	Node_t * a1 = createNode(1);
	Node_t * a2 = createNode(2);
	Node_t * a3 = createNode(3);
	Node_t * a4 = createNode(4);

	conbination(a2, a1, a3);
	conbination(a4, a2, NULL);

	Tree_t * tree = createTree(a1);

	InorderThreading(tree);

	InorderThreadedSearch(tree);

	Release(tree);
}