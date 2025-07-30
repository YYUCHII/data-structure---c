#include"AVLTree.h"

Tree_t * Create()
{
	Tree_t * tree = malloc(sizeof(Tree_t));

	tree->root = NULL;
	tree->num = 0;

	return tree;
}

//分割线

void releaseTool(Node_t * node)
{
	if(node == NULL) return;

	releaseTool(node->left);
	releaseTool(node->right);
	free(node);
}

void Release(Tree_t *tree)
{
	releaseTool(tree->root);
}

//分割线

int getHigh(Node_t * node)
{
	if(node == NULL) return 0;

	int lefthigh = getHigh(node->left) ;
	int righthigh = getHigh(node->right);

	return lefthigh > righthigh ? lefthigh + 1: righthigh + 1;
}

//分割线

/*
    RR:				 RL:
  		   x                 x 
  	     /   \		       /   \
	    n     n		      n     n
	         / \              /   \
            n   n  	         n     n
           	     \		    /
                  n		   n 
 */

Node_t* leftR(Node_t * x)
{
	Node_t * temp = x->right;
	x->right = temp->left;
	temp->left = x;

	return temp;
}

//分割线

/*
    LL:				LR:
  		   x                x 
  	     /   \		      /   \
	    n     n		     n     n
	   / \             /   \
      n   n  	      n     n
     /					     \
    n						  n
 */

Node_t * rightR(Node_t * x)
{
	Node_t * temp = x->left;
	x->left = temp->right;
	temp->right = x;
	
	return temp;
}

//分割线

Node_t * createNode(Element_t value)
{
	Node_t * node = malloc(sizeof(Node_t));
	node->left = node->right = NULL;
	node->value = value;

	return node;
}

//分割线

Node_t * insertTool(Node_t * node, Element_t value)
{
	if(node == NULL) return createNode(value);

	if(value < node->value ) node->left = insertTool(node->left, value);
	else if(node->value < value) node->right = insertTool(node->right, value);
	//如果相等，返回节点，不能返回NULL。
	else return node;

	//接下来判断node在插入完节点后是否还平衡

	int balance = getHigh(node->left) - getHigh(node->right);

	if(balance > 1)
	{
		//如果为LR，先转换为LL
		if(node->left->value < value) leftR(node->left);
		return rightR(node);
	}
	else if(balance < -1)
	{
		//如果为RL，先转换为RR
		if(value < node->right->value) rightR(node->right);
		return leftR(node);
	}

	return node;

}

void Insert(Tree_t * tree, Element_t value)
{
	tree->root = insertTool(tree->root, value);
	tree->num++;
}

//分割线

Node_t * findminback(Node_t * node)
{
	Node_t * min = node->right;

	while(min->left)
	{
		min = min->left;
	}

	return min;
}

int getbalance(Node_t * node)
{
	return getHigh(node->left) - getHigh(node->right);
}

Node_t * deleteTool(Node_t * node ,Element_t value)
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
		Node_t * min = findminback(node);
		node->value = min->value;
		node->right = deleteTool(node->right, min->value);
		//为什么这里不return ，因为这个度为2的节点，并没有被删除，而是底下的min被删了，它从下面归回来，自然要看删除了min的node是否还平衡
	}

	int balance = getbalance(node);

	if(balance > 1)
	{
	/*
    	LR:
  		        x 
  	     	  /   \
	    	 n     n
	       /   \
          n     n
     			 \
    			  n
 	 */
		if(getbalance(node->left) < 0) leftR(node->left);
		return rightR(node);
	}
	else if(balance < -1)
	{
	/*
    	RL:
  		    	x 
  	     	  /   \
	         n     n
	             /   \
                n     n
               /
       		  n 
 	 */
		if(getbalance(node->right) > 0) rightR(node->right);
		return leftR(node);
	}

	return node;
}

void Delete(Tree_t * tree, Element_t value)
{
	tree->root = deleteTool(tree->root,value);
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