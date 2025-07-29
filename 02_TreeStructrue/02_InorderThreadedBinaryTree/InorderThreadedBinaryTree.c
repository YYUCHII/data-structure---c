#include"InorderThreadedBinaryTree.h"

Node_t * createNode(Element_t value)
{
	Node_t * node = malloc(sizeof(Node_t));

	node->left = node->right = NULL;
	node->value = value;

	//初始化为虚线
	node->Lflag = node->Rflag = 0;

	return node;
}

//连了节点才是实现，没连就是虚线，线索化的线也是虚线
void conbination(Node_t *left, Node_t *node, Node_t *right)
{
	node->left = left;
	node->right = right;
	if(left) node->Lflag = 1;
	if(right) node->Rflag = 1;
}

void releaseTool(Node_t * node)
{
	if(node == NULL) return ;

	releaseTool(node->left);
	releaseTool(node->right);

	free(node);
}

void Release(Tree_t * tree)
{
	releaseTool(tree->root);
	free(tree);
}

Tree_t * createTree(Node_t * root)
{
	Tree_t * tree = malloc(sizeof(Tree_t));
	tree->root = root;

	return tree;
}

//中序线索化

//pre用来记录前驱，并且把前驱的后继指向cur(node)
static Node_t * pre = NULL ;

void inorderthreadingTool(Node_t * node)
{
	if(node == NULL) return ;

	inorderthreadingTool(node->left);

	//先处理前驱
	if(node->Lflag == 0) node->left = pre;
	
	//再处理前驱的后继
	if(pre && pre->Rflag == 0) pre->right = node;

	//在node去下一个节点前，pre记录当前node的节点，作为下一个节点的前驱
	pre = node;

	inorderthreadingTool(node->right);
}

void InorderThreading(Tree_t * tree)
{
	inorderthreadingTool(tree->root);
}

//线索化遍历
void Show(Node_t * node)
{
	printf("%d\t",node->value);
}

void InorderThreadedSearch(Tree_t * tree)
{
	Node_t * node = tree->root;

	while(node)
	{
		while(node->Lflag == 1) node = node->left;

		Show(node);

		while(node->Rflag == 0 && node->right != NULL) 
		{
			node = node->right;
			Show(node);
		}

		node = node->right;
	}
}

/*
	线索化遍历顺口溜：
	从根开始，
	先往左找虚线，
	再往右找实线，
	新根为实线右边的节点，
	再循环
*/