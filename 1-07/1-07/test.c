#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = malloc(sizeof(int));
	ps->_top = 0;
	ps->_capacity = 4;
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		ps->_capacity *= 2;
		STDataType *temp = (STDataType *)realloc(ps->_a, sizeof(STDataType)*(ps->_capacity));
		if (temp == NULL)
		{
			printf("申请内存失败\n");
			exit(-1);
		}
		else
		{
			ps->_a = temp;
		}
		
	}
	ps->_a[ps->_top] = data;
	++(ps->_top);
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	--(ps->_top);
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
typedef struct {
	Stack _pushST;
	Stack _popST;
} MyQueue;

/** Initialize your data structure here. */

int myQueuePeek(MyQueue* obj);
MyQueue* myQueueCreate() {
	MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
	StackInit(&q->_pushST);
	StackInit(&q->_popST);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->_pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek(obj);
	StackPop(&obj->_popST);
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (!StackEmpty(&obj->_popST))
	{
		return StackTop(&obj->_popST);
	}
	else
	{
		while (!StackEmpty(&obj->_pushST))
		{
			StackPush(&obj->_popST, StackTop(&obj->_pushST));
			StackPop(&obj->_pushST);
		}
		return StackTop(&obj->_popST);;
	}
}
int myQueueEmpty(MyQueue* obj) {
	if (StackEmpty(&obj->_popST) && StackEmpty(&obj->_pushST))
		return 1;
	else
		return 0;
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->_popST);
	StackDestroy(&obj->_pushST);
	free(obj);
}

int main()
{
	/*["MyQueue", "push", "push"]
	[[], [1], [2]]*/
	MyQueue* q = myQueueCreate();
	myQueuePush(q, 1);
	myQueuePush(q, 2);
	myQueuePush(q, 3);
	myQueuePush(q, 4);
	myQueuePush(q, 3);
	while (!myQueueEmpty(q))
	{
		printf("%d ", myQueuePeek(q));
		myQueuePop(q);
	}
	printf("\n");
	return 0;
}

/** Returns whether the queue is empty. */
//bool myQueueEmpty(MyQueue* obj) {
//	return StackEmpty(&obj->_popST) && StackEmpty(&obj->_pushST);
//}

//void myQueueFree(MyQueue* obj) {
//
//}

