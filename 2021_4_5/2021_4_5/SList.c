#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>

#include"SList.h"

//打印
void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;//让cur指向它的下一个结点
	}
	printf("\n");
}

//创建新结点
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;

	return node;
}

//尾插
void SListPushBack(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);   //创建新结点
	//空表情况
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		//先遍历找尾
		SLTNode* tail = *pplist;  //pplist是第一个结点的地址
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		SLTNode* newnode = BuySLTNode(x);   //创建新结点

		tail->next = newnode;  //最后一个结点指向新指针
	}
	
}


//头插
void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);   //创建新结点
	newnode->next = *pplist;//头插在第二个
	*pplist = newnode;
}


//尾删
void SListPopBack(SLTNode** pplist)
{
	//1.没有结点
	//2.一个结点
	//3.多个结点
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

		prev->next = NULL;  //必须加上这一句，也要置为null，因为前面prev = tail,释放了tail,tail->next也为空了
	}
	
}

//头删
void SListPopFront(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = (*pplist)->next;  // 存一份，若直接释放，找不到下一个结点的地址
		free(*pplist);

		*pplist = next;
	}
}

//单链表查找
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
	assert(pos);//判断插入位置是否为空

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}


//pos之前插入(比较麻烦)
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);

	//若pos在第一个
	if (pos == *pplist)  //头插
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

//销毁单链表
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