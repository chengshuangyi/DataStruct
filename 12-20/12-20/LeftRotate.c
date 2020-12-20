#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

//��������
void LeftRotate1(char *arr,int count)
{
	assert(arr);
	int len = strlen(arr);
	//����count��
	while (count--)
	{
		//��ǰ�����ƶ�֮ǰ�ȱ���arr[0]
		char temp = arr[0];
		int i = 0;
		///����һ��
		//��arr[1]��arr[len-1]��ǰ�ƶ�
		while (i < len - 1)
		{
			arr[i] = arr[i + 1];
			i++;
		}
		arr[len - 1] = temp;
	}	
}

//����
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
	//����ǰcount���ַ�
	reverse(arr, 0, count - 1);
	//���ú�len-count���ַ�
	reverse(arr, count, len - 1);
	//��������
	reverse(arr, 0, len - 1);
}

void LeftRotate3(char *arr, int count)
{
	int len = strlen(arr);
	char *double_arr = (char *)malloc(sizeof(char)*(len * 2 + 1));
	strcpy(double_arr, arr);//copy����
	strcat(double_arr, arr);//�ַ�������
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
