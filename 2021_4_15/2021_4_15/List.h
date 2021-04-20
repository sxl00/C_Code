#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#pragma once

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

void ListPrint(ListNode* phead);

ListNode* BuyListNode(LTDataType x);

ListNode* ListInit();

void ListPushBack(ListNode* phead, LTDataType x);

void ListPushFront(ListNode* phead, LTDataType x);

void ListPopBack(ListNode* phead);

void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);

void ListInsert(ListNode* pos, LTDataType x);

void ListErase(ListNode* pos);

int ListEmpty(ListNode* phead);

int ListSize(ListNode* phead);

void ListDestroy(ListNode* phead);

