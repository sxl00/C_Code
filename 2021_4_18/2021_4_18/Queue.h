#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;

//定义结点
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

//定义队列
 typedef struct Queue  //若不用typedef,则后面函数定义变量必须使用struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;


//初始化
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//进队列
void QueuePush(Queue* pq, QDataType x);

//出队列
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

bool QueueEmpty(Queue* pq);

int QueueSize(Queue* pq);






