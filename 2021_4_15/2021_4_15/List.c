#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"List.h"
#include<stdlib.h>

void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	
	return phead;
}

//β��
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* tail = phead->prev; //β��ͷ���ǰһ��ָ��
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	//ListInsert(phead, x);
}

//ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	//phead newnode first
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}

//βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	//��ֻ��һ�����ʱ���´��벻����
	assert(phead->next != phead);
	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	free(tail);

	tailPrev->next = phead;
	phead->prev = tailPrev;

	
}

//ͷɾ
void ListPopFront(ListNode* phead)
{
	/*assert(phead);

	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;

	free(first);
	first = NULL;

	phead->next = second;
	second->prev = phead;*/

	ListErase(phead->next);

}

//���ҽ��
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//������
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

//ɾ��ĳ���
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);
}

//�շ���1���ǿշ���0
int ListEmpty(ListNode* phead)
{
	return phead->next = phead ? 1 : 0;
}

int ListSize(ListNode* phead)
{
	assert(phead);
	int size = 0;
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}
	return size;
}

void ListDestroy(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}