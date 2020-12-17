#include<stdio.h>
int main()
{
	int num = 13;
	//int占4个字节，32个bit位，i：0-31
	int i = 31;
	printf("%d二进制为:\n",num);
	while (i >= 0)
	{
		//每次将num右移一位 去 &1
		printf("%d ", (num >> i) & 1);
		i--;
	}
	printf("\n");
	
	printf("%d奇数位:\n",num);

	//注意 i=i-2
	for (i = 0; i < 31; i += 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");

	printf("%d偶数位:\n", num);
	for (i = 1; i <= 31; i += 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	return 0;
}