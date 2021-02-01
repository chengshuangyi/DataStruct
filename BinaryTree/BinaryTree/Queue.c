#include"Queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode *newnode = (QNode *)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("�ڴ治��\n");
		exit(-1);
	}

	//��ʼ��newnode
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_head == NULL)
	{
		q->_head = q->_tail = newnode;
	}
	else 
	{
		q->_tail->_next = newnode;
		q->_tail = newnode;
	}
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	//assert(q->_head);
	QNode *next = q->_head->_next;
	free(q->_head);
	q->_head = next;

	if (q->_head == NULL)
	{
		q->_tail = NULL;
	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_head);
	return q->_head->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_tail);
	return q->_tail->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	QNode *cur = q->_head;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	/*if (q->_head == NULL)
		return 1;
	return 0;*/
	return q->_head == NULL ? 1 : 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode *cur = q->_head;
	while (cur)
	{
		QNode *next = cur->_next;
		free(cur);
		cur = next;
	}

	//��head��tail����ΪNULL
	q->_head = q->_tail = NULL;
}