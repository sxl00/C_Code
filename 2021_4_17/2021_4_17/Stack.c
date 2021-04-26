#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//初始化栈
void StackInit(Stack* pst)
{
	assert(pst);

	//不方便增容
	/*pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;*/

	pst->a = (STDataType*)malloc(sizeof(STDataType)* 4);
	pst->top = 0;
	pst->capacity = 4;
}

//销毁栈
void StackDestroy(Stack*  pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//入栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp =(STDataType*) realloc(pst->a,sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);  //结束整个程序
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	//入数据
	pst->a[pst->top] = x;
	pst->top++;
}


//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	pst->top--;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	return pst->a[pst->top - 1];
}
bool StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}

int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}



