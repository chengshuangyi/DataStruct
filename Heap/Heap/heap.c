#include"heap.h"

//��ӡ������
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

//���µ����㷨  (ǰ�᣺������������С��)
void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;     //���ڵ�
	int child = parent * 2 + 1;      //���ӽڵ�

	while (child < n)
	{
		//�ҳ����Һ���С���Ǹ�
		if (child + 1<n && a[child + 1] < a[child])
			++child;

		//�������С�ڸ��ף��ͽ���
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

//���ϵ����㷨
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2; 
	
	// ���ܰ�parent>=0��Ϊ��ֹѭ����������Ϊparentһֱ>=0(��ѭ��)
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

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	//��ʼ���� 
	hp->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_capacity = hp->_size = n;
	
	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_capacity = hp->_size = 0;
}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	//����
	if (hp->_size >= hp->_capacity)
	{
		hp->_capacity *= 2;
		HPDataType *tmp = (HPDataType *)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
		if (tmp == NULL)
		{
			printf("�����ڴ�ʧ��\n");
			exit(-1);
		}
		hp->_a = tmp;
	}

	hp->_a[hp->_size] = x;
	++(hp->_size);
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}

// �ѵ�ɾ��   (ɾ���Ѷ�������)
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	--hp->_size;
	AdjustDown(hp->_a, hp->_size, 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	if (HeapSize(hp) > 0)
		return 1;
	return 0;
}

// ��������ж�����
void HeapSort(int* a, int n)
{
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//����
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		//����ѡС��
		AdjustDown(a, end, 0);
		--end;
	}
}

//��СTopK����
void PrintTopK(int* a, int n, int k)
{
	assert(a);
	Heap hp;
	HeapCreate(&hp, a, n);
	for (int i = 0; i < k; i++)
	{
		printf("��%d��%d  ", i+1, HeapTop(&hp));
		HeapPop(&hp);
	}
}
