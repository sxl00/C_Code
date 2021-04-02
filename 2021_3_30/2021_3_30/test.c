#include"SeqList.h"



void TestSeqList1()
{
	SeqList s = { NULL, 0, 0 };
	SeqListInit(&s);

	//β��
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);


	//ͷ��
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0); 
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);


	//βɾ
	SeqListPopBack(&s);
	SeqListPopBack(&s);



	//ͷɾ
	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);

	SeqListDestory(&s);
}

void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);

	//β��
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);

	SeqListInsert(&s, 2, 30);

	SeqListInsert(&s, 0, 30);

	SeqListErase(&s, 0);
	SeqListErase(&s, 2);

	SeqListModify(&s,0,-1);

	SeqListPrint(&s);

	SeqListDestory(&s);

}
int main()
{
	//TestSeqList1();
	TestSeqList2();
	return 0;
}