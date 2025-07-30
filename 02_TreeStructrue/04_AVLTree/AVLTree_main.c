#include"AVLTree.h"

int main()
{
	Tree_t * tree = Create();

	Insert(tree, 1);
	Insert(tree, 2);
	Insert(tree, 3);

	Delete(tree, 2);

	printf("num = %d\n",tree->num);
	InorderShow(tree);
	



	Release(tree);
}