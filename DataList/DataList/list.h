#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//��������
typedef int DataType;

//�ṹ�嶨��
typedef struct ListNode
{
	DataType data;
	ListNode *prev;
	ListNode *next;
}ListNode;

//˫�������ɾ�Ĳ�

//β������ɾ��
void ListPushBack(ListNode *phead,DataType x);