#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"SList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
}
int main()
{
	/*struct SListNode* node1 = (struct SListNode*)malloc(sizeof(struct SListNode));
	struct SListNode* node2 = (struct SListNode*)malloc(sizeof(struct SListNode));
	struct SListNode* node3 = (struct SListNode*)malloc(sizeof(struct SListNode));
	struct SListNode* node4 = (struct SListNode*)malloc(sizeof(struct SListNode));
	
	printf("%p\n", node1);
	printf("%p\n", node2);
	printf("%p\n", node3);
	printf("%p\n", node4);*/

	TestSList1();
	return 0;
}