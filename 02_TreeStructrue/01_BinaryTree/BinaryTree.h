#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Element_t ;

typedef struct _node{
	Element_t value;
	struct _node * left;
	struct _node * right;
}Node_t ;

typedef struct{
	Node_t * root;
}Tree_t;

//生成一个二叉树：先将二叉树的所有节点生成，再拼接为一颗二叉树，再传给root。这样就生成了一颗二叉树。(无插入函数)

//1，生成节点函数
Node_t * createNode(Element_t value);

//2,拼接节点成树
void conbination(Node_t * left , Node_t * node ,Node_t * right);

//3,选择一个节点作为这颗树的根节点，传给函数去跟踪
Tree_t * createTree(Node_t * root);

//最后三种遍历方式去遍历。
//递归为Recursion
//深度优先遍历为DFS（deep first search）

//1,深度优先递归遍历
void RDFS(Tree_t * tree);

//2,广度遍历
void BFS(Tree_t * tree);

//3,深度优先非递归遍历
void NRDFS(Tree_t * tree);

//后序递归遍历
void Release(Tree_t * tree);
