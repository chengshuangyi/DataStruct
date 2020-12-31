#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//��������
typedef int DataType;

//�ṹ�嶨��
typedef struct ListNode
{
	DataType data;
	struct ListNode *prev;
	struct ListNode *next;
}ListNode;

//����һ������ڵ�
ListNode *BuyListNode(DataType x);
//��������
void ListClear(ListNode *phead);
void ListDestory(ListNode *phead);

//�����ʼ��
ListNode *ListInit();

//��ӡ����
void PrintList(ListNode *phead);

//˫�������ɾ�Ĳ�
//β��
void ListPushBack(ListNode *phead,DataType x);
//βɾ
void ListPopBack(ListNode *phead);
//ͷ��
void ListPushFront(ListNode *phead, DataType x);
//ͷɾ
void ListPopFront(ListNode *phead);

//����
ListNode *ListFind(ListNode *phead, DataType x);
//��posλ��ǰ�����
void ListInsert(ListNode *pos, DataType x);
//ɾ��posλ�õĽ��
void ListErase(ListNode *pos);