#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;

//������
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

//�������
 typedef struct Queue  //������typedef,����溯�������������ʹ��struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;


//��ʼ��
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//������
void QueuePush(Queue* pq, QDataType x);

//������
void QueuePop(Queue* pq);

//ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//ȡ��β����
QDataType QueueBack(Queue* pq);

bool QueueEmpty(Queue* pq);

int QueueSize(Queue* pq);






