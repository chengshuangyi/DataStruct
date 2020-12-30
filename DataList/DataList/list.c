#include"list.h"

ListNode * BuyNode(DataType x)
{
	ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}
void ListPushBack(ListNode *phead, DataType x)
{
	assert(phead);
	ListNode *newnode = BuyNode(x);
	ListNode *tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}