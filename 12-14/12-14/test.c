#include"Seqlist.h"

void test1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
    SeqListPrint(&s);

	int pos=SeqListFind(&s, 5);
	if (pos != 0)
	{
		SeqListErase(&s, pos);
	}

	SeqListDestory(&s);	
	SeqListPrint(&s);
}
int main()
{
	test1();
	return 0;
}