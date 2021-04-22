#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
struct Stack
{
	STDataType* a;  //数组
	int top;       //栈顶
	int capacity;  //容量，方便增容
};

typedef struct Stack Stack;

//只改变形参，改变不了实参
void StackInit(Stack* pst);
void StackDestroy(Stack*  pst);

void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

STDataType StackTop(Stack* pst);

//空返回1,非空返回0
bool StackEmpty(Stack* pst);

int StackSize(Stack* pst);