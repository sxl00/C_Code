#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
#include<stdio.h>
//堆向下调整法: 左右子树是小堆或大堆
//（1）选出左右孩子中小的那一个
//（2）小的孩子与父亲比较
//（3）如果小的孩子比父亲小，则跟父亲交换，
//并把原来孩子位置当成父亲继续往下调整，直到走到叶子结点
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
	//	//选出左右孩子中小的那一个
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


//排升序，建大堆
//void HeapSort(int* a,int n)
//{
//	//建堆
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

	//建堆
	//从最后一个非叶子结点开始调整
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
