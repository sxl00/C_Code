#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#pragma once

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;  //指针指向下一个结点，也是同样的结构
}SLTNode;

//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//	struct ListNode* prev;
//};


//单向-不带头-不循环
void SListPrint(SLTNode* plist);

void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

//单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//插入
//pos之后插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//pos之前插入
void SListInsertBefore(SLTNode* pos, SLTDataType x);

void SListEraseAfter(SLTNode* pos);

void SListDestory(SLTNode* pplist);