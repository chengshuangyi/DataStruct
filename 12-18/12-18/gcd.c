#include<stdio.h>

//շת�����
int gcd1(int x, int y)
{
	//�ж�x/y�����Ƿ�Ϊ0
	int z = x % y;

	//ֱ������Ϊ0��������ѭ��
	while(z)
	{
		//ѭ�������У���������x��������y�����µ�����z
		x = y;
		y = z;
		z = x % y;
	}
	//����yΪ���Լ��
	return y;
}

//���������
int gcd2(int x, int y)
{
	int sum1 = 1;
	//���ж� x y�Ƿ���ż��
	while ((x % 2 == 0) && (y % 2 == 0))
	{
		sum1 *= 2;
		x = x / 2;
		y = y / 2;
	}

	while (1)
	{
		//��֤�����������ڼ�������Ȼ�ͽ���˳��
		if (x < y)
		{
			int temp = x;
			x = y;
			y = temp;
		}

		//�����s��
		int s = x - y;
		//�жϲ� �� ���� �Ƿ���ȣ�����ǣ�����ѭ����
		if (y == s)
			break;
		else
		{
			x = y;
			y = s;
		}
	}
	//���Լ������Լ�������ɸ�2�Ļ���ڶ����е���������=��ĳ˻�
	return y * sum1;
}

int main()
{
	int a = 98;
	int b = 63;
	int max1 = gcd1(a, b);
	int max2 = gcd2(a, b);
	printf("%d  %d�����Լ��Ϊ %d\n", a, b, max1);
	printf("%d  %d�����Լ��Ϊ %d\n", a, b, max2);
	return 0;
}