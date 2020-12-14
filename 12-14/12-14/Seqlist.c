#include"Seqlist.h"

//��ʼ��
void SeqListInit(SeqList* ps)
{
	ps->capacity = 4;
	ps->a = (SLDataType *)malloc(sizeof(SLDataType)*ps->capacity);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
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

//��ӡ
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

//����Ƿ���Ҫ����
void SeqListCheckCapacity(SeqList *ps)
{
	//������ˣ����ٿռ�
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType *)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
		if (ps->a == NULL)
		{
			//����ʧ�ܣ�ֱ���˳�
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}

//β��
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}

//ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	//�Ӻ���ǰ�����ƶ�
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

//ͷɾ
void SeqListPopFront(SeqList* ps) 
{
	assert(ps);
	int start = 0;
	//��ǰ�����ƶ�
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	//�жϲ���λ���Ƿ�Ϸ�
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size-1;
	//��posλ�ÿ�ʼ���������Ԫ�شӺ���ǰ�ƶ�
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;

}

// ˳���ɾ��posλ�õ�ֵ
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

// ˳������
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//�ҵ�x���򷵻��±�
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}
