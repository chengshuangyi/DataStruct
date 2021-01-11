typedef struct {
	int *_a;//数组
	int _front; //头
	int _rear;  //尾
	int _k;  //存储有效元素的个数

} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *q = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	q->_a = (int *)malloc(sizeof(int)*(k + 1));  //多开一个元素的空间
	q->_front = 0;
	q->_rear = 0;
	q->_k = k;
	return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	else
	{
		obj->_a[obj->_rear] = value;
		++obj->_rear;
		obj->_rear %= obj->_k + 1;
		return true;
	}
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	else
	{
		++obj->_front;
		obj->_front %= obj->_k + 1;
		return true;
	}
}


int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		return obj->_a[obj->_front];
	}

}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		int tail = obj->_rear - 1;
		if (obj->_rear == 0)
			tail = obj->_k;
		return obj->_a[tail];
	}
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->_rear == obj->_front;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return obj->_front == (obj->_rear + 1) % (obj->_k + 1);
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_a);
	free(obj);
}
