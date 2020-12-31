#include"list.h"

//开辟一个链表节点
ListNode *BuyListNode(DataType x)
{
	ListNode * newnode = (ListNode *)malloc(sizeof(ListNode));
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}

//链表初始化
ListNode *ListInit()
{
	ListNode *phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//打印链表
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

//尾插
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

//尾删
void ListPopBack(ListNode *phead)
{
	assert(phead);
	//不能删掉头节点
	assert(phead->next != phead);
	ListNode *tail = phead->prev;
	ListNode *tailPrev = tail->prev;
	phead->prev = tailPrev;
	tailPrev->next = phead;
	free(tail);
}

//头插
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
//头删
void ListPopFront(ListNode *phead)
{
	assert(phead);
	//不能删掉头节点
	assert(phead->next != phead);
	ListNode *first = phead->next;
	ListNode *second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
}

//查找
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

//在pos位置前面插入
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

//删除pos位置的结点
void ListErase(ListNode *pos)
{
	ListNode *prev = pos->prev;
	ListNode *next = pos->next;
	//prev pos next
	prev->next = next;
	next->prev = prev;
}

//销毁链表
void ListClear(ListNode *phead)
{
	assert(phead);
	//清理所有数据节点，保留头节点，可以继续使用
	ListNode *cur = phead->next;
	while (cur != phead)
	{
		ListNode *next = cur->next;
		free(cur);
		cur = next;
	}
	//头节点自身形成一个循环
	phead->next = phead;
	phead->prev = phead;
}
void ListDestory(ListNode *phead)
{
	ListClear(phead);
	free(phead);
}
