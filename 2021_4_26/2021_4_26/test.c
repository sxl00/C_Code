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

//��һ�����Ľ����

//˼·һ����������
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

//˼·��
int TreeSize(BTNode* root)
{
	//�ݹ���������˷���ֵ
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//��Ҷ�ӽ��ĸ���
//�գ�return 0     
//Ҷ��:return 1   
//�ǿ��Ҳ���Ҷ��:return ������Ҷ�ӽڵ���+������Ҷ�ӽ����
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

//���k��Ľ����
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left, k - 1)+
		TreeKLevelSize(root->right,k-1);
}

//�ҵ�Ԫ��Ϊx�Ľ��
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	//���Լ�����
	if (root->data == x)
		return root;

	//������������
	//BTNode* lret = (BTNode*)malloc(sizeof(BTNode));
	BTNode* lret = TreeFind(root->left, x);
	if (lret)
	{
		return lret;
	}

	//������û�ҵ���������������
	//BTNode* rret = (BTNode*)malloc(sizeof(BTNode));
	BTNode* rret = TreeFind(root->right, x);
	if (rret)
	{
		return rret;
	}

	//���Ҿ�û���ҵ�
	return NULL;
}


void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;  //�ص����õĵط�
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
		return;  //�ص����õĵط�
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
		return;  //�ص����õĵط�
	}
	PostOrder(root->left);
	
	PostOrder(root->right);
	printf("%c ", root->data);

}

// һ�㣬���ѡ��һ��ָ�룬����Ұָ�����⣬����BinaryTreeDestory���ˣ���ָ���ÿ�
//�������ֽӿڵ�һ����
//������������
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//��α���
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

//�ж϶������Ƿ�����ȫ������
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