#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"SList.h"
#include"List.h"

//void TestSList1()
//{
//	SLTNode** pplist = NULL;
//	//SLTNode* plist = NULL;
//	//尾插
//	SListPushBack(&pplist, 1);
//	SListPushBack(&pplist, 2);
//	SListPushBack(&pplist, 3);
//	SListPushBack(&pplist, 4);
//
//	//头插
//	SListPushFront(&pplist, 0);
//
//	//尾删
//	SListPopBack(&pplist);
//	//SListPopBack(&pplist);
//
//	//头删
//	SListPopFront(&pplist);
//	//SListPrint(pplist);
//	SLTNode* pos = SListFind(pplist, 3);
//	SListInsertAfter(pos, 30);
//	SListInsertBefore(&pplist, pos, 30);
//	//if (pos) //pos不等于空 
//	//{
//	//	//兼具修改的作用
//	//	//pos->data = 30;
//	//	printf("找到了\n");
//
//	//}
//	//else
//	//{
//	//	printf("没有找到\n");
//	//}
//
//	SListEraseAfter(pos);
//
//	SListPrint(pplist);
//	SListDestory(pplist);
//}

void TestList()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPushBack(plist, 7);
	ListPrint(plist);

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	ListPrint(plist);

	ListPopBack(plist);
	//ListPopBack(plist);

	ListPopFront(plist);
	//ListPopFront(plist);
	ListNode* pos = ListFind(plist, 4);
	if (pos)
	{  
		ListInsert(pos, 40);
	}
	ListPrint(plist);

	//没有用二级指针，保持一致性
	ListDestroy(plist);
	plist = NULL;
	
}
int main()
{
	//TestSList1();
	TestList();
	return 0;
}