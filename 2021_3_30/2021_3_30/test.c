#include"SeqList.h"



void TestSeqList1()
{
	SeqList s = { NULL, 0, 0 };
	SeqListInit(&s);

	//尾插
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);


	//头插
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0); 
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);


	//尾删
	SeqListPopBack(&s);
	SeqListPopBack(&s);



	//头删
	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);

	SeqListDestory(&s);
}

void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);

	//尾插
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


void menu()
{
	printf("*************************");
	printf("1.尾插数据   2.头插数据\n");
	printf("3.尾删数据   4.头删数据\n");
	printf("5.查找数据   6.打印数据\n");
	printf("0.退出程序             \n");
	printf("*************************");
}
int main()
{
	//TestSeqList1();
	//TestSeqList2();

	SeqList s;
	SeqListInit(&s);
	int option = 0;
	do
	{
		menu();
		scanf("%d",&option);
		int x = 0;
		switch (option)
		{
		case 1:
			printf("请输入要尾插的数据，以-1结束：");
			while (1)
			{
				scanf("%s", &x);
				if (x == -1)
					break;
			}
			
			
			SeqListPushBack(&s, x);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			SeqListPrint(&s);
			break;
		default:
			break;
		}
	} while (option != 0);
	SeqListDestory(&s);
	return 0;
}