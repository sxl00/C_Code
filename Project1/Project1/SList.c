#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>
#include"SList.h"

void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;  //����һ������ַ���Լ����Լ����ߵ���һ�����
	}
	printf("\n");
}


//�����½��
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;

	return node;
}

//β��
//Ҫ�ı��㣬������ָ�룬��ָ��ĵ�ַ���ܸı�
void SListPushBack(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		//��β
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

//ͷ��
void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;
	*pplist = newnode;

}

//βɾ
void SListPopBack(SLTNode** pplist)
{
	//1.û�н��
	//2.һ�����
	//3.������
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}


