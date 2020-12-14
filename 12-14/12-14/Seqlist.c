#include"Seqlist.h"

//初始化
void SeqListInit(SeqList* ps)
{
	ps->capacity = 4;
	ps->a = (SLDataType *)malloc(sizeof(SLDataType)*ps->capacity);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	ps->size = 0;
}

void SeqListDestory(SeqList* ps)
{
	free(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//打印
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//检查是否需要扩容
void SeqListCheckCapacity(SeqList *ps)
{
	//如果满了，开辟空间
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType *)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
		if (ps->a == NULL)
		{
			//扩容失败，直接退出
			printf("扩容失败\n");
			exit(-1);
		}
	}
}

//尾插
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}

//头插
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	//从后向前依次移动
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

//头删
void SeqListPopFront(SeqList* ps) 
{
	assert(ps);
	int start = 0;
	//从前往后移动
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	//判断插入位置是否合法
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size-1;
	//从pos位置开始，后边所以元素从后往前移动
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;

}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size );
	int start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//找到x，则返回下标
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}
