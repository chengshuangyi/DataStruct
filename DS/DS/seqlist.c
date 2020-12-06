#include"seqlist.h"

int SeqListFull(SeqList *plist)
{
	assert(plist != NULL);
	if (plist->size >= plist->capacity)
		return 1;
	return 0;
}

int SeqListEmpty(SeqList *plist)
{
	assert(plist != NULL);
	if (plist->size == 0)
		return 1;
	return 0;
}

//����ʵ��
void SeqListInit(SeqList *plist)
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType *)malloc(sizeof(ElemType) * plist->capacity);
	plist->size = 0;
}

void SeqListPushBack(SeqList* plist, ElemType x)
{
	assert(plist != NULL);
	//����
	if (SeqListFull(plist))
	{
		printf("˳�������������β������\n");
		return;
	}
	plist->base[plist->size] = x;
	plist->size++;
	
}

void SeqListPrint(SeqList *plist)
{
	assert(plist != NULL);
	int i = 0;
	for (i = 0; i < plist->size; i++)
	{
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}

void SeqListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	//�п�
	if (SeqListEmpty(plist))
	{
		printf("˳���Ϊ�գ�����β������ɾ��...\n");
		return;
	}
	plist->size--;
}

void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	//����
	if (SeqListFull(plist))
	{
		printf("˳�������������ͷ������\n");
		return;
	}
	int i = 0;
	for (i = plist->size; i > 0; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;
}

void SeqListPopFront(SeqList* plist)
{
	assert(plist != NULL);
	//�п�
	if (SeqListEmpty(plist))
	{
		printf("˳���Ϊ�գ�����ͷ������ɾ��...\n");
		return;
	}
	int i = 0;
	for (i == 0; i < plist->base[plist->size]-1; i++)
	{
		plist->base[i] = plist->base[i + 1];

	}
	plist->size--;
}
