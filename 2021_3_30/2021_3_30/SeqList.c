#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SeqList* seq)
{
	//assert(seq != NULL);
	assert(seq);

	seq->a = NULL;
	seq->size = seq->capacity = 0;
}
void SeqListDestory(SeqList* seq)
{
	assert(seq);

	free(seq->a);
	seq->a = NULL;
	seq->capacity = seq->size = 0;
}

void SeqListPrint(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->a[i]);
	}
	printf("\n");
}

void SeqCheckCapacity(SeqList* seq)
{
	//���ˣ���Ҫ����
	if (seq->size == seq->capacity)
	{
		int newcapacity = seq->capacity == 0 ? 4 : seq->capacity * 2;
		SeqDataType* newA = realloc(seq->a, sizeof(SeqDataType)*newcapacity);
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		seq->a = newA;
		seq->capacity = newcapacity;
	}
}

void SeqListPushBack(struct SeqList* seq, SeqDataType x) //β��
{
	assert(seq);
	//���ˣ���Ҫ����
	if (seq->size == seq->capacity)
	{
		int newcapacity = seq->capacity == 0 ? 4:seq->capacity* 2;
		//realloc��һ����ԭ������
		SeqDataType* newA = realloc(seq->a, sizeof(SeqDataType)*newcapacity);
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		seq->a = newA;
		seq->capacity = newcapacity;
	}
	seq->a[seq->size] = x;
	seq->size++;

}
void SeqListPushFront(struct SeqList* seq, SeqDataType x) //ͷ��
{
	assert(seq);
	SeqCheckCapacity(seq);
	int end = seq->size - 1;
	while (end >= 0)
	{
		seq->a[end + 1] = seq->a[end];
		end--;
	}
	seq->a[0] = x;
	seq->size++;  //���Ҫ�ټ�һ���ռ��С
}

void SeqListPopBack(struct SeqList* seq)//βɾ
{
	assert(seq);
	assert(seq->size > 0);
	--seq->size;
}

void SeqListPopFront(struct SeqList* seq) //ͷɾ
{
	assert(seq);
	assert(seq->size > 0);
	/*int start = seq->a[0];
	for (int i = 1; i < seq->size; i++)
	{
		seq->a[i - 1] = seq->a[i];
	}
	--seq->size;*/

	int begin = 0;
	while (begin < seq->size - 1)
	{
		seq->a[begin] = seq->a[begin + 1];
		++begin;
	}
	seq->size--;
}

int SeqListFind(SeqList* seq, SeqDataType x)
{
	assert(seq);
	assert(seq->size > 0);
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* seq,int pos, SeqDataType x)
{
	assert(seq);
	assert(pos >= 0 && pos < seq->size);
	SeqCheckCapacity(seq);
	
	int end = seq->size - 1;
	while (end >= pos)
	{
		seq->a[end + 1] = seq->a[end];
		--end;
	}
	seq->a[pos] = x;
	seq->size++;
}

void SeqListErase(SeqList* seq, int pos)
{
	assert(seq);
	assert(pos >= 0 && pos < seq->size);

	int begin = pos;
	while (begin <= seq->size - 1)
	{
		seq->a[begin] = seq->a[begin + 1];
		++begin;
	}
	seq->size--;
}

void SeqListModify(SeqList* seq, int pos, SeqDataType x)
{
	assert(seq);

	assert(pos >= 0 && pos < seq->size);

	seq->a[pos] = x;
}