#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#pragma once

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;  //ָ��ָ����һ����㣬Ҳ��ͬ���Ľṹ
}SLTNode;

//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//	struct ListNode* prev;
//};


//����-����ͷ-��ѭ��
void SListPrint(SLTNode* plist);

void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

//���������
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//����
//pos֮�����
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//pos֮ǰ����
void SListInsertBefore(SLTNode* pos, SLTDataType x);

void SListEraseAfter(SLTNode* pos);

void SListDestory(SLTNode* pplist);