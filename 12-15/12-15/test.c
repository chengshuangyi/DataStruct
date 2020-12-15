#include"SList.h"
int main()
{
	SListNode *phead = NULL;
	
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	//SListPushFront(&phead, 9);
	//SListPopBack(&phead);
	//SListPopFront(&phead);
	SListNode *a = SListFind(phead, 2);
	//SListInsertAfter(a, 7);
	SListEraseAfter(a);
	SListPrint(phead);
	SListDestory(phead);
	return 0;
}