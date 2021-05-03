#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void Swap(int* p1, int* p2)
{
		int tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
}
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

void AdjustUp(int* a,  int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//void HeapInit(HPDataType* a, int n);
//初始化
void HeapInit(HP* php, HPDataType* a, int n)
{
	assert(php);
	//函数的功能是从源内存地址的起始位置开始拷贝若干个字节到目标内存地址中
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

//添加到最后，再进行向上调整
void HeapPush(HP* php, HPDataType x)
{
	//满了需要增容
	if (php->size == php->capacity)
	{
		//realloc是对已有的空间进行扩容
		HPDataType* tmp = (HPDataType*)realloc(php->a, php->capacity * 2 * sizeof(HPDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp; 
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

//先进行第一个与最后一个交换，再向下调整
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[php->size - 1], &php->a[0]);
	//删掉换到最后的这个原堆顶数据
	php->size--;

	AdjustDown(php->a, php->size, 0);
}


HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
void HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");

	//int num = 1;
	//int i = 0;
	//while (num < php->size)
	//{
	//	for (int j = 0; j < num; j++)
	//	{
	//		printf("%d ", php->a[i++]);
	//	}
	//	printf("\n");
	//	num *= 2;
	//}
	
}

int* getLeastNumbers(int* arr, int arrSize, int k){
	if (k == 0)
	{
		//*returnSize = 0;
		return NULL;
	}
	int* arrRet = (int*)malloc(sizeof(int)*k);
	//前k个数建立大堆
	for (int i = 0; i <k; i++)
	{
		arrRet[i] = arr[i];
	}
	for (int j = (k - 1 - 1); j >= 0; j--)
	{
		AdjustDown(arrRet, k, j);
	}


	//剩下的N-K个数，比堆顶的小，就替换堆顶数据，进堆
	for (int i = k; i < arrSize; i++)
	{
		if (arr[i] < arrRet[0])
		{
			arrRet[0] = arr[i];
			AdjustDown(arrRet, k, 0);
		}
	}
	//*returnSize = k;
	return arrRet;
}