#include"Queue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode *newnode = (QNode *)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("内存不足\n");
		exit(-1);
	}

	//初始化newnode
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

// 队头出队列 
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

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_head);
	return q->_head->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_tail);
	return q->_tail->_data;
}

// 获取队列中有效元素个数 
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

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	/*if (q->_head == NULL)
		return 1;
	return 0;*/
	return q->_head == NULL ? 1 : 0;
}

// 销毁队列 
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

	//将head和tail都置为NULL
	q->_head = q->_tail = NULL;
}