#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
#include<stdio.h>
//�����µ�����: ����������С�ѻ���
//��1��ѡ�����Һ�����С����һ��
//��2��С�ĺ����븸�ױȽ�
//��3�����С�ĺ��ӱȸ���С��������׽�����
//����ԭ������λ�õ��ɸ��׼������µ�����ֱ���ߵ�Ҷ�ӽ��
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//
//void AdjustDown(int* a, int n, int parent)
//{
	//int child = parent * 2 + 1;
	//while (child < n)
	//{
	//	//ѡ�����Һ�����С����һ��
	//	if (child + 1 < n && a[child + 1] < a[child])
	//	{
	//		++child;
	//	}
	//	if (a[child] < a[parent])
	//	{
	//		Swap(&a[child], &a[parent]);
	//		parent = child;
	//		child = 2 * parent + 1;
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
//}


//�����򣬽����
//void HeapSort(int* a,int n)
//{
//	//����
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0); 
//		--end;
//	}
//}


int main()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(a) / sizeof(a[0]);
	//AdjuestDown(a, n, 0);

	//����
	//�����һ����Ҷ�ӽ�㿪ʼ����
	/*for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
	AdjustDown(a, n, i);
	}*/
	HP hp;
	HeapInit(&hp, a, n);

	HeapPush(&hp, 8);
	HeapPrint(&hp);

	HeapPush(&hp, 88);
	HeapPrint(&hp);

	HeapPop(&hp, 88);

	HeapPrint(&hp);

	getLeastNumbers(a, n, 5);
	HeapPrint(&hp);
	HeapDestroy(&hp);

	return 0;
}
