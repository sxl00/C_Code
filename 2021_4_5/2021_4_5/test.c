#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"SList.h"

void TestSList1()
{
	SLTNode** pplist = NULL;
	//SLTNode* plist = NULL;
	//β��
	SListPushBack(&pplist, 1);
	SListPushBack(&pplist, 2);
	SListPushBack(&pplist, 3);
	SListPushBack(&pplist, 4);

	//ͷ��
	SListPushFront(&pplist, 0);

	//βɾ
	SListPopBack(&pplist);
	//SListPopBack(&pplist);

	//ͷɾ
	SListPopFront(&pplist);
	//SListPrint(pplist);
	SLTNode* pos = SListFind(pplist, 3);
	SListInsertAfter(pos, 30);
	SListInsertBefore(&pplist,pos, 30);
	//if (pos) //pos�����ڿ� 
	//{
	//	//����޸ĵ�����
	//	//pos->data = 30;
	//	printf("�ҵ���\n");

	//}
	//else
	//{
	//	printf("û���ҵ�\n");
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