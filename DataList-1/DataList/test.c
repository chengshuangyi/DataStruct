#include"list.h"

//
//void Test1()
//{
//	ListNode *phead = ListInit();
//	ListPushBack(phead, 1);
//	ListPushBack(phead, 2);
//	ListPushBack(phead, 3);
//	PrintList(phead);
//	ListPopBack(phead);
//	ListPopBack(phead);
//	ListPopBack(phead);
//	PrintList(phead);
//	ListPushFront(phead, 1);
//	ListPushFront(phead, 2);
//	ListPushFront(phead, 3);
//	ListPushFront(phead, 4);
//	ListPushFront(phead, 5);
//	PrintList(phead);
//	ListPopFront(phead);
//	ListPopFront(phead);
//	ListPopFront(phead);
//	PrintList(phead);
//}

void Test2()
{
	ListNode *phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	PrintList(phead);
	ListNode *pos = ListFind(phead, 2);
	ListInsert(pos, 200);
	PrintList(phead);
	ListErase(pos);
	PrintList(phead);
	//ListDestory(phead);
	//PrintList(phead);
}
int main()
{
	//Test1();
	Test2();
	return 0;
}