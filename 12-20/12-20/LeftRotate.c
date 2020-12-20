#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

//左旋三次
void LeftRotate1(char *arr,int count)
{
	assert(arr);
	int len = strlen(arr);
	//左旋count次
	while (count--)
	{
		//从前往后移动之前先保存arr[0]
		char temp = arr[0];
		int i = 0;
		///左旋一次
		//将arr[1]到arr[len-1]往前移动
		while (i < len - 1)
		{
			arr[i] = arr[i + 1];
			i++;
		}
		arr[len - 1] = temp;
	}	
}

//逆置
void reverse(char *arr, int left, int right)
{
	while (left < right)
	{
		char temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}

void LeftRotate2(char *arr, int count)
{
	int len = strlen(arr);
	//逆置前count个字符
	reverse(arr, 0, count - 1);
	//逆置后len-count个字符
	reverse(arr, count, len - 1);
	//整体逆置
	reverse(arr, 0, len - 1);
}

void LeftRotate3(char *arr, int count)
{
	int len = strlen(arr);
	char *double_arr = (char *)malloc(sizeof(char)*(len * 2 + 1));
	strcpy(double_arr, arr);//copy函数
	strcat(double_arr, arr);//字符串连接
	int i = 0;
	for (i = 0; i < len; i++)
	{
		arr[i] = double_arr[i + count];
	}
	free(double_arr);
}

int main()
{
	char arr[] = "ABCDEFG";
	int count = 3;
	LeftRotate1(arr, count);
	//LeftRotate2(arr, count);
	//LeftRotate3(arr, count);
	printf("%s\n", arr);
	return 0;
}
