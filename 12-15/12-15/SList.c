#include"SList.h"

//��̬����һ���ڵ�
SListNode* BuySListNode(SLDataType x)
{
	SListNode *newnode = (SListNode *)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("����ڵ�ʧ��/n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//��ӡ
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


//β��
void SListPushBack(SListNode** pplist, SLDataType x)
{
	assert(pplist);
	SListNode *newnode = BuySListNode(x);
	//����ǿ�����������ͷָ���´����Ľ��
	if (*pplist== NULL)
	{
		*pplist = newnode;
	}
	else
	{
		//��β
		SListNode *tail = *pplist;
		while (tail->next!=NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//ͷ��
void SListPushFront(SListNode** pplist, SLDataType x)
{
	assert(pplist);
	SListNode *newhead = BuySListNode(x);
	newhead->next = *pplist;
	*pplist = newhead;
}

//βɾ
void SListPopBack(SListNode** pplist)
{
	//���б�
	if (*pplist == NULL)
	{
		return;
	}
	//ֻ��һ�����
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		(*pplist) = NULL;
	}
	//�ж���ڵ�
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

//ͷɾ
void SListPopFront(SListNode** pplist)
{
	//��
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

//����
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
	printf("û�ҵ�\n");
	return NULL;
}

// ��������posλ��֮�����x, ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	assert(pos);
	SListNode *newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ������ɾ��posλ��֮���ֵ,����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	//pos��û�н�㣬ֱ�ӷ���
	if (pos->next == NULL)
	{
		return;
	}
	//pos��ֻ��һ���ڵ�
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

// �����������
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
