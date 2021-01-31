#include"heap.h"

//打印堆数据
void Print(Heap* hp)
{
	assert(hp->_size > 0);
	for (int i=0; i<hp->_size; i++)
	{
		printf("%d  ", hp->_a[i]);
	}
}

void Swap(HPDataType *p1, HPDataType *p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向下调整算法  (前提：左右子树都是小堆)
void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;     //父节点
	int child = parent * 2 + 1;      //孩子节点

	while (child < n)
	{
		//找出左右孩子小的那个
		if (child + 1<n && a[child + 1] < a[child])
			++child;

		//如果孩子小于父亲，就交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}		
	}
}

//向上调整算法
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2; 
	
	// 不能把parent>=0作为终止循环条件，因为parent一直>=0(死循环)
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break; 
		}
	}
}

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	//初始化堆 
	hp->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_capacity = hp->_size = n;
	
	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_capacity = hp->_size = 0;
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	//扩容
	if (hp->_size >= hp->_capacity)
	{
		hp->_capacity *= 2;
		HPDataType *tmp = (HPDataType *)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
		if (tmp == NULL)
		{
			printf("开辟内存失败\n");
			exit(-1);
		}
		hp->_a = tmp;
	}

	hp->_a[hp->_size] = x;
	++(hp->_size);
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}

// 堆的删除   (删除堆顶的数据)
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	--hp->_size;
	AdjustDown(hp->_a, hp->_size, 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	if (HeapSize(hp) > 0)
		return 1;
	return 0;
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		//继续选小的
		AdjustDown(a, end, 0);
		--end;
	}
}

//最小TopK问题
void PrintTopK(int* a, int n, int k)
{
	assert(a);
	Heap hp;
	HeapCreate(&hp, a, n);
	for (int i = 0; i < k; i++)
	{
		printf("第%d：%d  ", i+1, HeapTop(&hp));
		HeapPop(&hp);
	}
}
