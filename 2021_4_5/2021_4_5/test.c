#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"SList.h"

void TestSList1()
{
	SLTNode** pplist = NULL;
	//SLTNode* plist = NULL;
	//尾插
	SListPushBack(&pplist, 1);
	SListPushBack(&pplist, 2);
	SListPushBack(&pplist, 3);
	SListPushBack(&pplist, 4);

	//头插
	SListPushFront(&pplist, 0);

	//尾删
	SListPopBack(&pplist);
	//SListPopBack(&pplist);

	//头删
	SListPopFront(&pplist);
	//SListPrint(pplist);
	SLTNode* pos = SListFind(pplist, 3);
	SListInsertAfter(pos, 30);
	SListInsertBefore(&pplist,pos, 30);
	//if (pos) //pos不等于空 
	//{
	//	//兼具修改的作用
	//	//pos->data = 30;
	//	printf("找到了\n");

	//}
	//else
	//{
	//	printf("没有找到\n");
	//}

	SListEraseAfter(pos);

	 SListPrint(pplist);
	 SListDestory(pplist);
}

int main()
{
	TestSList1();
	return 0;
}