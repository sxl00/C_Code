#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//��̬���ݱ�
//#define N 1000
//struct SeqList
//{
//	int a[N];
//	int size;
//};


//��̬���ݱ�
typedef int SeqDataType;
typedef struct SeqList
{
	SeqDataType* a;
	int size;    //��Ч���ݵĸ���,�൱�����鳤��
	int capacity;  //�����ռ�
}SeqList, SEQ;

//�ڴ��и��������ݵĽṹ��ɾ��ĵĽӿ�

void SeqListInit(SeqList* seq);//��ʼ��
void SeqListDestory(SeqList* seq);  //����

void SeqListPrint(SeqList* seq);

void SeqListPushBack(struct SeqList* seq, SeqDataType x);  //β��
void SeqListPushFront(struct SeqList* seq, SeqDataType x);  //ͷ��
void SeqListPopBack(struct SeqList* seq);  //βɾ
void SeqListPopFront(struct SeqList* seq);  //ͷɾ

int SeqListFind(SeqList* seq, SeqDataType x);  //����

void SeqListInsert(SeqList* seq, SeqDataType x);  //����

void SeqListErase(SeqList* seq, int pos);  //ɾ��ĳλ�õ���

void SeqListModify(SeqList* seq, int pos, SeqDataType x);  //�޸�