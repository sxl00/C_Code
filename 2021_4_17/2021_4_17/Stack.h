#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
struct Stack
{
	STDataType* a;  //����
	int top;       //ջ��
	int capacity;  //��������������
};

typedef struct Stack Stack;

//ֻ�ı��βΣ��ı䲻��ʵ��
void StackInit(Stack* pst);
void StackDestroy(Stack*  pst);

void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

STDataType StackTop(Stack* pst);

//�շ���1,�ǿշ���0
bool StackEmpty(Stack* pst);

int StackSize(Stack* pst);