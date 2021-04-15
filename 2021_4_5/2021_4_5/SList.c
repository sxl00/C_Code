#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>

#include"SList.h"

//��ӡ
void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;//��curָ��������һ�����
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
void SListPushBack(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);   //�����½��
	//�ձ����
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		//�ȱ�����β
		SLTNode* tail = *pplist;  //pplist�ǵ�һ�����ĵ�ַ
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		SLTNode* newnode = BuySLTNode(x);   //�����½��

		tail->next = newnode;  //���һ�����ָ����ָ��
	}
	
}


//ͷ��
void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);   //�����½��
	newnode->next = *pplist;//ͷ���ڵڶ���
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

		prev->next = NULL;  //���������һ�䣬ҲҪ��Ϊnull����Ϊǰ��prev = tail,�ͷ���tail,tail->nextҲΪ����
	}
	
}

//ͷɾ
void SListPopFront(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = (*pplist)->next;  // ��һ�ݣ���ֱ���ͷţ��Ҳ�����һ�����ĵ�ַ
		free(*pplist);

		*pplist = next;
	}
}

//���������
SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);//�жϲ���λ���Ƿ�Ϊ��

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}


//pos֮ǰ����(�Ƚ��鷳)
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);

	//��pos�ڵ�һ��
	if (pos == *pplist)  //ͷ��
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}

}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	SLTNode* next = pos->next;

	if (next != NULL)
	{
		SLTNode* nextnext = next->next;
		free(next);
		pos->next = nextnext;
	}
}

//���ٵ�����
void SListDestory(SLTNode* pplist)
{
	SLTNode* q = pplist;
	while (pplist != NULL)
	{
		q = pplist->next;
		free(pplist);
		//delete(pplist);
		pplist = q;
	}
	q = NULL;
}