#include"BinaryTree.h"

Node_t * createNode(Element_t value)
{
	Node_t * node= malloc(sizeof(Node_t));

	node->left = node->right = NULL;
	node->value = value;

	return node;
}

void conbination(Node_t * left , Node_t * node ,Node_t * right)
{
	node->left = left;
	node->right =right;
}

Tree_t * createTree(Node_t * root)
{
	Tree_t * tree= malloc(sizeof(Tree_t));

	tree->root = root;

	return tree;
}

//分割线
//后续遍历实现release

void releaseTool(Node_t * node)
{
	if(node == NULL)
	{
		return;
	}

	releaseTool(node->left);
	releaseTool(node->right);
	free(node);
}

void Release(Tree_t * tree)
{
	releaseTool(tree->root);
	free(tree);
}

//分割线

void RDFSTool(Node_t * node)
{
	if(node == NULL) return ;

	printf("%d\t",node->value);

	RDFSTool(node->left);
	RDFSTool(node->right);
}

void RDFS(Tree_t * tree)
{
	RDFSTool(tree->root);
}

//分割线

void BFS(Tree_t * tree)
{
	Node_t * queue[5];
	int front = 0;
	int rear = 0;

	rear = (rear + 1) % 5;
	queue[rear] = tree->root;

	while(front != rear)
	{
		front = (front + 1) % 5;
		Node_t * p = queue[front];
		printf("%d\t",p->value);

		if(p->left)
		{
			rear = (rear + 1) % 5;
			queue[rear] = p->left;
		}
		if(p->right)
		{
			rear = (rear + 1) % 5;
			queue[rear] = p->left;
		}
	}
}

void NRDFS(Tree_t * tree)
{
	Node_t * stack[5];
	int top = 0;

	stack[top] = tree->root;
	top++;

	while(top != 5)
	{
		top--;
		Node_t * p = stack[top];
		printf("%d\t",p->value);

		if(p->right)
		{
			stack[top] = p->right;
			top++;
		}
		if(p->left)
		{
			stack[top] = p->left;
			top++;
		}
	}

}