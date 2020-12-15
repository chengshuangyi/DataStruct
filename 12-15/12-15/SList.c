#include"SList.h"

//动态申请一个节点
SListNode* BuySListNode(SLDataType x)
{
	SListNode *newnode = (SListNode *)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("申请节点失败/n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//打印
void SListPrint(SListNode* plist)
{
	if (plist == NULL)
		return;
	else
	{
		SListNode *cur = plist;
		while (cur)
		{
			printf("%d ", cur->data);
			cur = cur->next;
		}
		printf("\n");
	}
}


//尾插
void SListPushBack(SListNode** pplist, SLDataType x)
{
	assert(pplist);
	SListNode *newnode = BuySListNode(x);
	//如果是空链表，则链表头指向新创建的结点
	if (*pplist== NULL)
	{
		*pplist = newnode;
	}
	else
	{
		//找尾
		SListNode *tail = *pplist;
		while (tail->next!=NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//头插
void SListPushFront(SListNode** pplist, SLDataType x)
{
	assert(pplist);
	SListNode *newhead = BuySListNode(x);
	newhead->next = *pplist;
	*pplist = newhead;
}

//尾删
void SListPopBack(SListNode** pplist)
{
	//空列表
	if (*pplist == NULL)
	{
		return;
	}
	//只有一个结点
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		(*pplist) = NULL;
	}
	//有多个节点
	else
	{
		SListNode *pre = NULL;
		SListNode *tail = *pplist;
		while (tail->next)
		{
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		pre->next = NULL;
	}
}

//头删
void SListPopFront(SListNode** pplist)
{
	//空
	if ((*pplist) == NULL)
	{
		return;
	}
	else
	{
		SListNode *next = (*pplist)->next;
		free(*pplist);
		*pplist = next;
	}
}

//查找
SListNode* SListFind(SListNode* plist, SLDataType x)
{
	assert(plist);
	SListNode *cur = plist;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	printf("没找到\n");
	return NULL;
}

// 单链表在pos位置之后插入x, 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	assert(pos);
	SListNode *newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 单链表删除pos位置之后的值,分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	//pos后没有结点，直接返回
	if (pos->next == NULL)
	{
		return;
	}
	//pos后只有一个节点
	else if(pos->next->next ==NULL)
	{
		free(pos->next);
		pos->next = NULL;
	}
	else
	{
		SListNode *next = pos->next;
		SListNode *nextnext = next->next;
		pos->next = nextnext;
		free(next);
		/*pos->next = pos->next->next;
		free(pos->next);*/
	}
}

// 单链表的销毁
void SListDestory(SListNode* plist)
{
	SListNode *cur = plist;
	while (cur)
	{
		SListNode *next = cur->next;
		free(cur);
		cur = next;
	}
	plist == NULL;
}
