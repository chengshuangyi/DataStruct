#include"list.h"

//����һ������ڵ�
ListNode *BuyListNode(DataType x)
{
	ListNode * newnode = (ListNode *)malloc(sizeof(ListNode));
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}

//�����ʼ��
ListNode *ListInit()
{
	ListNode *phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//��ӡ����
void PrintList(ListNode *phead)
{
	assert(phead);
	ListNode *cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//β��
void ListPushBack(ListNode *phead, DataType x)
{
	assert(phead);
	ListNode *newnode = BuyListNode(x);
	ListNode *tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//βɾ
void ListPopBack(ListNode *phead)
{
	assert(phead);
	//����ɾ��ͷ�ڵ�
	assert(phead->next != phead);
	ListNode *tail = phead->prev;
	ListNode *tailPrev = tail->prev;
	phead->prev = tailPrev;
	tailPrev->next = phead;
	free(tail);
}

//ͷ��
void ListPushFront(ListNode *phead, DataType x)
{
	assert(phead);
	ListNode *newnode = BuyListNode(x);
	ListNode *first = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}
//ͷɾ
void ListPopFront(ListNode *phead)
{
	assert(phead);
	//����ɾ��ͷ�ڵ�
	assert(phead->next != phead);
	ListNode *first = phead->next;
	ListNode *second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
}

//����
ListNode *ListFind(ListNode *phead, DataType x)
{
	assert(phead);
	ListNode *cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
}

//��posλ��ǰ�����
void ListInsert(ListNode *pos, DataType x)
{
	ListNode *prev = pos->prev;
	ListNode *newnode = BuyListNode(x);
	//prev  newnode  pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

//ɾ��posλ�õĽ��
void ListErase(ListNode *pos)
{
	ListNode *prev = pos->prev;
	ListNode *next = pos->next;
	//prev pos next
	prev->next = next;
	next->prev = prev;
}

//��������
void ListClear(ListNode *phead)
{
	assert(phead);
	//�����������ݽڵ㣬����ͷ�ڵ㣬���Լ���ʹ��
	ListNode *cur = phead->next;
	while (cur != phead)
	{
		ListNode *next = cur->next;
		free(cur);
		cur = next;
	}
	//ͷ�ڵ������γ�һ��ѭ��
	phead->next = phead;
	phead->prev = phead;
}
void ListDestory(ListNode *phead)
{
	ListClear(phead);
	free(phead);
}
