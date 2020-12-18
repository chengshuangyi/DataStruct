#include<stdio.h>

//辗转相除法
int gcd1(int x, int y)
{
	//判断x/y余数是否为0
	int z = x % y;

	//直到余数为0，则跳出循环
	while(z)
	{
		//循环过程中，将除数给x，余数给y，求新的余数z
		x = y;
		y = z;
		z = x % y;
	}
	//除数y为最大公约数
	return y;
}

//更相减损术
int gcd2(int x, int y)
{
	int sum1 = 1;
	//先判断 x y是否都是偶数
	while ((x % 2 == 0) && (y % 2 == 0))
	{
		sum1 *= 2;
		x = x / 2;
		y = y / 2;
	}

	while (1)
	{
		//保证，被减数大于减数，不然就交换顺序
		if (x < y)
		{
			int temp = x;
			x = y;
			y = temp;
		}

		//差放在s中
		int s = x - y;
		//判断差 和 减数 是否相等，如果是，跳出循环。
		if (y == s)
			break;
		else
		{
			x = y;
			y = s;
		}
	}
	//最大公约数就是约掉的若干个2的积与第二步中等数（减数=差）的乘积
	return y * sum1;
}

int main()
{
	int a = 98;
	int b = 63;
	int max1 = gcd1(a, b);
	int max2 = gcd2(a, b);
	printf("%d  %d的最大公约数为 %d\n", a, b, max1);
	printf("%d  %d的最大公约数为 %d\n", a, b, max2);
	return 0;
}