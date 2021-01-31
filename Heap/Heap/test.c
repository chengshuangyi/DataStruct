#include"heap.h"

int main()
{
	int a[] = { 2,3,65,6,9,8,54,4,7,11,89 };
	Heap hp;
	HeapCreate(&hp, a, sizeof(a) / sizeof(HPDataType));
	PrintTopK(a, sizeof(a) / sizeof(HPDataType),3);
	HeapPush(&hp, 55);
	//Print(&hp);
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	HeapDestory(&hp);
	return 0;
}