#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* lessHead, *lessTail, *greaterHead, *greaterTail;
		lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		lessTail->next = NULL;
		greaterTail->next = NULL;

		struct ListNode* cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				lessTail->next = cur;  //尾插到小的值的链表中
				lessTail = lessTail->next;
			}
			else
			{
				greaterTail->next = cur;  //尾插到大的值的链表中
				greaterTail = greaterTail->next;
			}
			cur = cur->next;  //原来链表依次往后移动
		}
		//链接两个链表
		lessTail->next = greaterTail->next;
		greaterTail->next = NULL;   //关键语句，若少这一步，可能会形成环，造成死循环


		pHead = lessHead->next;
		free(lessHead);
		free(greaterHead);

		return pHead;
	}
};


	void PrintList(struct ListNode* cur)
	{
		//struct ListNode cur = head;
		while (cur)
		{
			printf("%d->",cur->val);
			cur = cur->next;
		}
	}
	int main()
	{
		struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));

		n1->val = 2;
		n2->val = 4;
		n3->val = 9;
		n4->val = 3;
		n5->val = 2;
		n6->val = 1;
		n7->val = 6;

		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		n4->next = n5;
		n5->next = n6;
		n6->next = n7;
		n7->next = NULL;

		struct ListNode* head = Partition().partition(NULL, 5);
		PrintList(head);

		return 0;
	}

