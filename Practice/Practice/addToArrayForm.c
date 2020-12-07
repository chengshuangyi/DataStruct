/*对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。*/
#include<stdio.h>
int* addToArrayForm(int* A, int ASize, int K)
{
	int num = 0;
	int i = 0;
	for (i = 0; i < ASize; i++)
	{
		num = num * 10 + A[i];
	}
	int add = num + K;
	
	for (i = 0; i < ASize; i++)
	{
		A[i] = num ^ (ASize - 1 - i);
	}
	return A;
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 34;
	int* result = addToArrayForm(arr, n, x);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", result[i]);
	}
	
	return 0;
}