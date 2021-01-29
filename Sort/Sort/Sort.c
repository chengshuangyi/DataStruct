#include"Sort.h"
#include"Stack.h"

//打印数组
void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1;i++)
	{
		//将end+1 往有序区间[0,end]中插入，使其保持有序
		int end = i;
		int insert = a[end + 1];

		while (end >= 0)
		{
			if (insert < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = insert;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	//1. gap>1是预排序，让数组接近有序
	//2. gap==1，就相当于直接插入排序，保证有序
	int gap = n;
	
	//多组并排
	while (gap > 1)
	{
		gap = gap / 3 + 1;      //+1保证了最后一次gap一定是1

		//gap==1,最后一次相当于直接插入排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int insert = a[end + gap];
			while (end >= 0)
			{
				if (insert < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = insert;
		}
		//Print(a, n);
	}
}

void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini;
		int maxi;
		mini = maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
				maxi = i;
			if(a[i] < a[mini])
				mini = i;	
		}
		Swap(&a[begin], &a[mini]);

		//如果begin和maxi位置重叠，需要对maxi进行修正
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}

// 堆排序
//向下调整算法
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		//找出左右孩子中大的数据给child
		if (child + 1< n && a[child + 1] > a[child])
			++child;

		//如果child位置数据大于parent位置数据，进行交换
		if (a[child] > a[parent])
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
//时间复杂度：O(N*logN)
void HeapSort(int* a, int n)
{
	//建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n , i);
	}

	int end = n - 1;
	//用建大堆算法排升序
	for (end = n - 1; end >= 0; --end)
	{
		//将堆顶数据与a[end]位置数据进行交换
		Swap(&a[end], &a[0]);

		//将前 end 个数据继续用向下调整算法进行建大堆
		AdjustDown(a, end, 0);
	}
}

// 冒泡排序
// 时间复杂度 O(N^2)
void BubbleSort(int* a, int n)
{
	for (int end = n - 1; end > 0; --end)
	{ 
		int flag = 1;
		//一趟冒泡排序
		for (int i = 0; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 0;
			}	
		}
		//如果一趟冒泡过程中，没有发生交换，证明数组前部分已经有序，不需要再进行冒泡
		if (flag)
			break;
	}
}

//三数取中
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (end - begin) / 2;
	if (a[begin] > a[mid])
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] > a[end])
			return end;
		else
			return begin;
	}
	else    //a[begin] < a[mid]
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
}

// 快速排序hoare版本(左右指针法)   [begin,end]
int PartSort1(int* a, int begin, int end)
{
	//将三数取中的中位数和a[end]交换
	int MidIndex = GetMidIndex(a, begin, end);
	Swap(&a[MidIndex], &a[end]);

	//选最右边的a[end]作为基准值
	int divIndex = end;
	while (begin < end)
	{
		//begin找大
		while (begin < end&&a[begin] <= a[divIndex])
		{
			++begin;
		}
		//end找小
		while (begin < end&&a[end] >= a[divIndex])
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}

	//将a[divIndex]放在正确位置(最终要放的位置)
	Swap(&a[begin], &a[divIndex]);
	return begin;
}

//挖坑法  [begin,end] 
int PartSort2(int* a, int begin, int end)
{
	//将三数取中的中位数和a[end]交换
	int MidIndex = GetMidIndex(a, begin, end);
	Swap(&a[MidIndex], &a[end]);
	//a[end]为坑，坑的意思是，这个位置值被拿走了，可以被覆盖新的值
	int key = a[end];
	while (begin < end)
	{
		//begin从左边找比key大的值填到右边的坑，a[begin]位置成为新的坑
		while (begin < end&&a[begin] <= key)
			++begin;
		a[end] = a[begin];

		//end从右边找比key小的值填到左边的坑，a[end]位置成为新的坑
		while (begin < end&&a[end] >= key)
			--end;
		a[begin] = a[end];
	}
	//相遇位置的坑填入key的值
	a[begin] = key;
	return begin;
}

// 前后指针法  [begin,end]
int PartSort3(int* a, int begin, int end)
{
	//将三数取中的中位数和a[end]交换
	int MidIndex = GetMidIndex(a, begin, end);
	Swap(&a[MidIndex], &a[end]);

	int keyIndex = end;
	int pre = begin - 1;
	int cur = begin;
	while (cur < end)
	{
		//如果a[cur]<a[keyIndex]并且++pre和cur不相等，则交换a[pre]和a[cur]的值
		//if (a[cur] < a[keyIndex])
		if (a[cur] < a[keyIndex] && ++pre!=cur)
			Swap(&a[pre], &a[cur]);
		cur++;
	}
	Swap(&a[++pre], &a[keyIndex]);
	return pre;
}

// 快速排序递归实现  
//[left,right]
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;

	int gap = right - left + 1;
	if (gap >= 10)
	{
		int div = PartSort3(a, left, right);
		//printf("[%d,%d]%d[%d,%d]\n", left, div - 1, div, div + 1, right);
		//Print(a + left, right - left + 1);
		//[left,div-1] div [div+1,right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	//区间小于10的时候，不使用快排，减少递归次数
	else
	{
		InsertSort(a + left, gap);
	}
}

// 快速排序 非递归实现  时间复杂度O(N*logN) 空间复杂度O(logN)
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		//[begin,end]
		int div = PartSort3(a, begin, end);
		//[begin,div-1]div[div+1,end]
		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}
		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}	
	}
	StackDestroy(&st);
}

// 归并排序递归实现  时间复杂度O(N*logN) 空间复杂度O(N)
//[begin1,end1] [begin2,end2]
void MergeArr(int *a, int begin1, int end1, int begin2, int end2, int *tmp)
{
	//归并[left,mid] [mid+1,right]有序
	int left = begin1;
	int right = end2;
	int mid = (right + left) / 2;
	int tmpIndex = left;
	//将a[begin1]和a[begin2]比较，对区间[left,right]进行排序
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[tmpIndex++] = a[begin1++];
		else
			tmp[tmpIndex++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[tmpIndex++] = a[begin1++];
	while (begin2 <= end2)
		tmp[tmpIndex++] = a[begin2++];

	//将归并好的区间[left,right]的数据，从tmp数组拷贝到数组a对应位置
	for (int i = left; i <= right; i++)
		a[i] = tmp[i];
}

//[left, right]
void _MergeSort(int *a, int left, int right, int *tmp)
{
	//递归分割区间
	if (left >= right)
		return;

	int mid = (right + left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid +1 , right, tmp);

	MergeArr(a, left, mid, mid + 1, right, tmp);
}

void MergeSort(int* a, int n)
{
	assert(a);
	int *tmp = (int *)malloc(sizeof(int)*n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int *tmp = (int *)malloc(sizeof(int)*n);
	int gap = 1;
	while (gap < n )
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			//合并时只有第一组，就不需要合并
			if (begin2 >= n)
				break;

			//合并时第二组只有部分数据，需要修正边界
			if (end2 >= n)
				end2 = n - 1;

			//[i,i+gap-1] [i+gap,i+2*gap-1]
			MergeArr(a, begin1, end1, begin2, end2, tmp);
		}
		Print(a, n);
		gap *= 2;
	}
	free(tmp);
}

// 计数排序
//时间复杂度 O(N+range)
//空间复杂度 O(range)
void CountSort(int* a, int n)
{
	assert(a);
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	int range = max - min + 1;
	int *countArray = (int *)malloc(sizeof(int)*range);
	memset(countArray, 0, sizeof(int)*range);
	
	//统计次数
	for (int i = 0; i < n; i++)
		countArray[a[i] - min]++;

	//排序
	int index = 0;
	for (int j = 0; j < range; j++)
	{
		while (countArray[j]--)
		{
			a[index++] = j + min;
		}
	}
}