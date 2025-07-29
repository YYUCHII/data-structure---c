#include"BinarySearchTree.h"

Tree_t * Create()
{
	Tree_t * tree = malloc(sizeof(Tree_t));

	tree->num = 0;
	tree->root = NULL;

	return tree;
}

//分割线

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

//分割线

void inordershowTool(Node_t * node)
{
	if(node == NULL) return;

	inordershowTool(node->left);
	printf("%d\t",node->value);
	inordershowTool(node->right);
}

void InorderShow(Tree_t * tree)
{
	inordershowTool(tree->root);
}

//分割线
//创建节点
Node_t * createNode(Element_t value)
{
	Node_t * node = malloc(sizeof(Node_t));
	node->left = node->right = NULL;
	node->value = value;

	return node;
}

//分割线

Node_t * insert(Node_t * node, Element_t value)
{
	if(node == NULL) return createNode(value);

	if(value < node->value) node->left = insert(node->left, value);
	else if(node->value < value) node->right = insert(node->right,value);
	
	return node;
}

void RInsert(Tree_t * tree, Element_t value)
{
	tree->root = insert(tree->root, value);
	tree->num++;
}

//分割线

void NRInsert(Tree_t * tree, Element_t value)
{
	Node_t * node = tree->root;
	Node_t * pre = NULL;

	//树为空的情况
	if(node == NULL)
	{
		tree->root = createNode(value);
		return ;
	} 

	while(node)
	{
		if(value < node->value)
		{
			pre = node;
			node = node->left;
		}
		else if(node->value < value)
		{
			pre = node;
			node = node->right;
		}
		else return;
	}

	if(pre->value < value)
	{
		pre->right = createNode(value);
	}
	else 
	{
		pre->left = createNode(value);
	}
	
}

//分割线
//找最小后继
Node_t * findminback(Node_t * node)
{
	Node_t * min = node->right;

	while(min->left)
	{
		min = min->left;
	}

	return min;
}

//分割线

Node_t * deleteTool(Node_t * node,Element_t value)
{
	if(node == NULL) return NULL;

	if(value < node->value) node->left = deleteTool(node->left, value);
	else if(node->value < value) node->right = deleteTool(node->right, value);
	else
	{
		Node_t * temp = NULL;
		if(node->left == NULL)
		{
			temp = node->right;
			free(node);
			return temp;
		}
		else if(node->right == NULL)
		{
			temp = node->left;
			free(node);
			return temp;
		}
		else 
		{
			Node_t * min = findminback(node);
			node->value = min->value;
			//不能改为free(min) ，因为如果min->right存在，那树就出错了
			node->right = deleteTool(node->right, min->value);
		}
	}
	return node;
}

void RDelete(Tree_t * tree,Element_t value)
{
	tree->root = deleteTool(tree->root, value);
	tree->num--;
}

//分割线
//删除度为2的节点
void dgrate2(Node_t * node)
{
	Node_t * min = node->right;
	Node_t * pre = NULL;
	while(min->left)
	{
		pre = min;
		min = min->left;
	}

	node->value = min->value;

	if(pre)
	{
		pre->left = min->right;
	}
	else 
	{
		node->right = min->right;
	}

	free(min);
}


//分割线

void NRDelete(Tree_t * tree, Element_t value)
{
	Node_t * node = tree->root;
	Node_t * pre = NULL;

	while(node)
	{
		if(value < node->value)
		{
			pre = node;
			node = node->left;
		}
		else if(node->value < value)
		{
			pre = node;
			node = node->right;
		}
		else break;
	}

	if(node == NULL) return ;

	Node_t * temp = NULL;

	if(pre)
	{
		if(node->left == NULL) temp = node->right;
		else if(node->right == NULL) temp = node->left;
		else
		{
			dgrate2(node);
			return;
		}

		if(pre->value > node->value) pre->left = temp;
		else pre->right = temp;
		free(node);
	}
	else 
	{
		if(node->left == NULL) tree->root = node->right;
		else if(node->right == NULL) tree->root = node->left;
		else
		{
			dgrate2(node);
			return ;
		}
		free(node);
	}
}