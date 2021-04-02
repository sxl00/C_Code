#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//静态数据表
//#define N 1000
//struct SeqList
//{
//	int a[N];
//	int size;
//};


//动态数据表
typedef int SeqDataType;
typedef struct SeqList
{
	SeqDataType* a;
	int size;    //有效数据的个数,相当于数组长度
	int capacity;  //容量空间
}SeqList, SEQ;

//内存中各管理数据的结构增删查改的接口

void SeqListInit(SeqList* seq);//初始化
void SeqListDestory(SeqList* seq);  //销毁

void SeqListPrint(SeqList* seq);

void SeqListPushBack(struct SeqList* seq, SeqDataType x);  //尾插
void SeqListPushFront(struct SeqList* seq, SeqDataType x);  //头插
void SeqListPopBack(struct SeqList* seq);  //尾删
void SeqListPopFront(struct SeqList* seq);  //头删

int SeqListFind(SeqList* seq, SeqDataType x);  //查找

void SeqListInsert(SeqList* seq, SeqDataType x);  //插入

void SeqListErase(SeqList* seq, int pos);  //删除某位置的数

void SeqListModify(SeqList* seq, int pos, SeqDataType x);  //修改