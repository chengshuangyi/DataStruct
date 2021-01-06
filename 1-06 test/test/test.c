#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _head;
	QNode* _tail;
}Queue;
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
	assert(q->_head);
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

typedef struct {
	Queue _q1;
	Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *st = (MyStack *)malloc(sizeof(MyStack));
	QueueInit(&st->_q1);
	QueueInit(&st->_q2);
	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->_q1))
	{
		QueuePush(&obj->_q1, x);
	}
	else
	{
		QueuePush(&obj->_q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue *empty = &obj->_q1;
	Queue *nonempty = &obj->_q2;
	if (QueueEmpty(&obj->_q2))
	{
		empty = &obj->_q2;
		nonempty = &obj->_q1;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	int top = QueueFront(nonempty);
	QueuePop(nonempty);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->_q1))
	{
		return QueueBack(&obj->_q1);
	}
	else
	{
		return QueueBack(&obj->_q2);
	}
}

/** Returns whether the stack is empty. */
//bool myStackEmpty(MyStack* obj) 
//{
//	return QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2);
//}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->_q1);
	QueueDestroy(&obj->_q2);
	free(obj);
}

int main()
{
	/*["MyStack", "push", "push", "top", "pop", "pop", "empty"]
	[[], [1], [2], [], [], [], []]*/
	MyStack *m = myStackCreate();
	myStackPush(m, 1);
	myStackPush(m, 2);
	int c = myStackTop(m);
	printf("%d", c);
	int a = myStackPop(m);
	printf("%d", a);
	int b = myStackPop(m);
	printf("%d", b);
	return 0;
}
/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/