#include"list.h"


void Test1()
{
	ListPushBack(phead, 1);
}

int main()
{
	ListNode *phead = ListInit(phead);
	Test1();
	return 0;
}