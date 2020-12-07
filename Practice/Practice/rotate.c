//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
#include<stdio.h>

//逆置
void reverse(int *left, int *right)
{
	while (left < right)
	{
		int temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
	
}

//打印
void Print(int *arr,int nums)
{
	int i = 0;
	for (i = 0; i < nums; i++)
	{
		printf("%d ", arr[i]);
	}
}

void rotate(int* nums, int numsSize, int k) 
{
	//首先逆置前numsSize-k个元素
	reverse(&nums[0], &nums[numsSize - 1 - k]);
	//然后逆置后k个元素
	reverse(&nums[numsSize - k], &nums[numsSize - 1]);
	//对整个数组进行逆置
	reverse(&nums[0], &nums[numsSize - 1]);
	
	Print(nums, numsSize);
}

int main()
{
	int arr[8] = { 11,67,90,-8,1,2,3,4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	rotate(arr, len, k);
	return 0;
}
