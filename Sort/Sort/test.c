#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 3, 4, 2, 1, 6, 0, 9, 5, 7, 8 };
	Print(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestShellSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	Print(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestSelectSort()
{
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int a[] = { 3, 4, 2, 1, 6, 0, 9, 5, 7, 8 };
	Print(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestHeapSort()
{
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int a[] = { 3, 4, 2, 1, 6, 0, 9, 5, 7, 8 };
	Print(a, sizeof(a) / sizeof(a[0]));
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestBubbleSort()
{
	int a[] = { 1,2,3,4,9,8,7,6,5 };
	//int a[] = { 3, 4, 2, 1, 6, 0, 9, 5, 7, 8 };
	Print(a, sizeof(a) / sizeof(a[0]));
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSortNonR()
{
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int a[] = { 3, 4, 9, 1, 6, 0, 9, 5, 9, 8 };
	Print(a, sizeof(a) / sizeof(a[0]));
	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) -1);
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestMergeSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int a[] = { 3, 4, 9, 1, 6, 0, 9, 5, 9, 8 };
	Print(a, sizeof(a) / sizeof(a[0]));
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
void TestMergeSortNonR()
{
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int a[] = { 3, 4, 9, 1, 6, 0, 9, 5 ,9};
	Print(a, sizeof(a) / sizeof(a[0]));
	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestCountSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int a[] = { 3, 4, 9, 1, 6, 0, 9, 5 ,9 };
	Print(a, sizeof(a) / sizeof(a[0]));
	CountSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 10000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSortNonR();
	//TestMergeSort();
	//TestMergeSortNonR();
	TestCountSort();
	//TestOP();
	return 0;
}