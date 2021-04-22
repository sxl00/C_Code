#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Stack.h"

void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	
	
	StackDestroy(&st);

}
int main()
{
	TestStack();
	return 0;
}