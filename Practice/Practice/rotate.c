//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ���
#include<stdio.h>

//����
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

//��ӡ
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
	//��������ǰnumsSize-k��Ԫ��
	reverse(&nums[0], &nums[numsSize - 1 - k]);
	//Ȼ�����ú�k��Ԫ��
	reverse(&nums[numsSize - k], &nums[numsSize - 1]);
	//�����������������
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
