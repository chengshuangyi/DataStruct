#include"Sort.h"
#include"Stack.h"

//��ӡ����
void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// ��������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1;i++)
	{
		//��end+1 ����������[0,end]�в��룬ʹ�䱣������
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

// ϣ������
void ShellSort(int* a, int n)
{
	//1. gap>1��Ԥ����������ӽ�����
	//2. gap==1�����൱��ֱ�Ӳ������򣬱�֤����
	int gap = n;
	
	//���鲢��
	while (gap > 1)
	{
		gap = gap / 3 + 1;      //+1��֤�����һ��gapһ����1

		//gap==1,���һ���൱��ֱ�Ӳ�������
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

// ѡ������
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

		//���begin��maxiλ���ص�����Ҫ��maxi��������
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}

// ������
//���µ����㷨
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		//�ҳ����Һ����д�����ݸ�child
		if (child + 1< n && a[child + 1] > a[child])
			++child;

		//���childλ�����ݴ���parentλ�����ݣ����н���
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
//ʱ�临�Ӷȣ�O(N*logN)
void HeapSort(int* a, int n)
{
	//�����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n , i);
	}

	int end = n - 1;
	//�ý�����㷨������
	for (end = n - 1; end >= 0; --end)
	{
		//���Ѷ�������a[end]λ�����ݽ��н���
		Swap(&a[end], &a[0]);

		//��ǰ end �����ݼ��������µ����㷨���н����
		AdjustDown(a, end, 0);
	}
}

// ð������
// ʱ�临�Ӷ� O(N^2)
void BubbleSort(int* a, int n)
{
	for (int end = n - 1; end > 0; --end)
	{ 
		int flag = 1;
		//һ��ð������
		for (int i = 0; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 0;
			}	
		}
		//���һ��ð�ݹ����У�û�з���������֤������ǰ�����Ѿ����򣬲���Ҫ�ٽ���ð��
		if (flag)
			break;
	}
}

//����ȡ��
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

// ��������hoare�汾(����ָ�뷨)   [begin,end]
int PartSort1(int* a, int begin, int end)
{
	//������ȡ�е���λ����a[end]����
	int MidIndex = GetMidIndex(a, begin, end);
	Swap(&a[MidIndex], &a[end]);

	//ѡ���ұߵ�a[end]��Ϊ��׼ֵ
	int divIndex = end;
	while (begin < end)
	{
		//begin�Ҵ�
		while (begin < end&&a[begin] <= a[divIndex])
		{
			++begin;
		}
		//end��С
		while (begin < end&&a[end] >= a[divIndex])
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}

	//��a[divIndex]������ȷλ��(����Ҫ�ŵ�λ��)
	Swap(&a[begin], &a[divIndex]);
	return begin;
}

//�ڿӷ�  [begin,end] 
int PartSort2(int* a, int begin, int end)
{
	//������ȡ�е���λ����a[end]����
	int MidIndex = GetMidIndex(a, begin, end);
	Swap(&a[MidIndex], &a[end]);
	//a[end]Ϊ�ӣ��ӵ���˼�ǣ����λ��ֵ�������ˣ����Ա������µ�ֵ
	int key = a[end];
	while (begin < end)
	{
		//begin������ұ�key���ֵ��ұߵĿӣ�a[begin]λ�ó�Ϊ�µĿ�
		while (begin < end&&a[begin] <= key)
			++begin;
		a[end] = a[begin];

		//end���ұ��ұ�keyС��ֵ���ߵĿӣ�a[end]λ�ó�Ϊ�µĿ�
		while (begin < end&&a[end] >= key)
			--end;
		a[begin] = a[end];
	}
	//����λ�õĿ�����key��ֵ
	a[begin] = key;
	return begin;
}

// ǰ��ָ�뷨  [begin,end]
int PartSort3(int* a, int begin, int end)
{
	//������ȡ�е���λ����a[end]����
	int MidIndex = GetMidIndex(a, begin, end);
	Swap(&a[MidIndex], &a[end]);

	int keyIndex = end;
	int pre = begin - 1;
	int cur = begin;
	while (cur < end)
	{
		//���a[cur]<a[keyIndex]����++pre��cur����ȣ��򽻻�a[pre]��a[cur]��ֵ
		//if (a[cur] < a[keyIndex])
		if (a[cur] < a[keyIndex] && ++pre!=cur)
			Swap(&a[pre], &a[cur]);
		cur++;
	}
	Swap(&a[++pre], &a[keyIndex]);
	return pre;
}

// ��������ݹ�ʵ��  
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
	//����С��10��ʱ�򣬲�ʹ�ÿ��ţ����ٵݹ����
	else
	{
		InsertSort(a + left, gap);
	}
}

// �������� �ǵݹ�ʵ��  ʱ�临�Ӷ�O(N*logN) �ռ临�Ӷ�O(logN)
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

// �鲢����ݹ�ʵ��  ʱ�临�Ӷ�O(N*logN) �ռ临�Ӷ�O(N)
//[begin1,end1] [begin2,end2]
void MergeArr(int *a, int begin1, int end1, int begin2, int end2, int *tmp)
{
	//�鲢[left,mid] [mid+1,right]����
	int left = begin1;
	int right = end2;
	int mid = (right + left) / 2;
	int tmpIndex = left;
	//��a[begin1]��a[begin2]�Ƚϣ�������[left,right]��������
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

	//���鲢�õ�����[left,right]�����ݣ���tmp���鿽��������a��Ӧλ��
	for (int i = left; i <= right; i++)
		a[i] = tmp[i];
}

//[left, right]
void _MergeSort(int *a, int left, int right, int *tmp)
{
	//�ݹ�ָ�����
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

// �鲢����ǵݹ�ʵ��
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
			//�ϲ�ʱֻ�е�һ�飬�Ͳ���Ҫ�ϲ�
			if (begin2 >= n)
				break;

			//�ϲ�ʱ�ڶ���ֻ�в������ݣ���Ҫ�����߽�
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

// ��������
//ʱ�临�Ӷ� O(N+range)
//�ռ临�Ӷ� O(range)
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
	
	//ͳ�ƴ���
	for (int i = 0; i < n; i++)
		countArray[a[i] - min]++;

	//����
	int index = 0;
	for (int j = 0; j < range; j++)
	{
		while (countArray[j]--)
		{
			a[index++] = j + min;
		}
	}
}