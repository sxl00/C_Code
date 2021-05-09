#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);

BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return  node;
}

//求一棵树的结点数

//思路一，遍历计数
//void TreeSize(BTNode* root,int* psize)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	++ (*psize);
//	TreeSize(root->left,psize);
//	TreeSize(root -> right,psize);
//
//	
//}

//思路二
int TreeSize(BTNode* root)
{
	//递归回来带回了返回值
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//求叶子结点的个数
//空：return 0     
//叶子:return 1   
//非空且不是叶子:return 左子树叶子节点数+右子树叶子结点数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//求第k层的结点数
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left, k - 1)+
		TreeKLevelSize(root->right,k-1);
}

//找到元素为x的结点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	//我自己不是
	if (root->data == x)
		return root;

	//从左子树上找
	//BTNode* lret = (BTNode*)malloc(sizeof(BTNode));
	BTNode* lret = TreeFind(root->left, x);
	if (lret)
	{
		return lret;
	}

	//左子树没找到，在右子树里找
	//BTNode* rret = (BTNode*)malloc(sizeof(BTNode));
	BTNode* rret = TreeFind(root->right, x);
	if (rret)
	{
		return rret;
	}

	//左右均没有找到
	return NULL;
}


void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;  //回到调用的地方
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;  //回到调用的地方
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);

}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;  //回到调用的地方
	}
	PostOrder(root->left);
	
	PostOrder(root->right);
	printf("%c ", root->data);

}

// 一般，如果选择一级指针，存在野指针问题，调用BinaryTreeDestory的人，把指针置空
//这样保持接口的一致性
//二叉树的销毁
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//层次遍历
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
		QueuePush(&q, front->left);
	}

	QueueDestroy(&q);

}

//判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front == NULL)
		{
			break;
		}

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

int main()
{
	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');

	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	printf("TreeSize:%d\n", TreeSize(A));
	printf("TreeSize:%d\n", TreeSize(A));

	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	printf("TreeKLevelSize:%d\n", TreeKLevelSize(A, 3));
	printf("TreeFind:%p\n", TreeFind(A, 'E'));
	printf("TreeFind:%p\n", TreeFind(A, 'X'));
	
	TreeLevelOrder(A);

	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(A));
	BinaryTreeDestory(A);
	A = NULL;
	return 0;
}