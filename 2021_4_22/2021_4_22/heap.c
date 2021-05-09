#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//大堆
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中小的那一个
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

//初始化
void HeapInit(HP* php, HPDataType* a, int n)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	memcpy(php->a, a, sizeof(HPDataType)*n);
	php->size = n;
	php->capacity = n;

	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->a, php->size, i);
	}

}

void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);
void HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");

	int num = 1;
	int i = 0;
	while (num < php->size)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%d ", php->a[i++]);
		}
		printf("\n");
		num *= 2;
	}
	
}