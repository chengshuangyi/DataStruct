//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
#include<stdio.h>
void merge(int *nums1,int m,int *nums2,int n)
{

	//将nums1和nums2合并
	int j = 0;
	for (j = 0; j < n; j++)
	{
		nums1[m+j] = nums2[j];
	}

	int i = 0;
	
	//冒泡排序
	for (i = 0; i < m + n - 1; i++)
	{
		int j = 0;
		for (j = 0; j < m + n - 1 - i; j++)
		{
			if (nums1[j] > nums1[j + 1])
			{
				int temp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int nums1[6] = { 1,2,3 };
	int nums2[3] = { 2,4,6 };
	merge(nums1, 3, nums2, 3);
	int i = 0;
	for (i = 0; i < 6 ; i++)
	{
		printf("%d ", nums1[i]);
	}
}