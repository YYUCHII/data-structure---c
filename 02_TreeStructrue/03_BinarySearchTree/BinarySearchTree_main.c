#include"BinarySearchTree.h"

int main()
{
	Tree_t * tree = Create();

	RInsert(tree, 5);

	NRInsert(tree,2);

	NRInsert(tree, 8);

	RInsert(tree, 1);

	RDelete(tree, 5);

	NRDelete(tree, 2);

	InorderShow(tree);

	



	Release(tree);

	return  0;
}