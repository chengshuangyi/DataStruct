#include<stdio.h>
int main()
{
	int num = 13;
	//intռ4���ֽڣ�32��bitλ��i��0-31
	int i = 31;
	printf("%d������Ϊ:\n",num);
	while (i >= 0)
	{
		//ÿ�ν�num����һλ ȥ &1
		printf("%d ", (num >> i) & 1);
		i--;
	}
	printf("\n");
	
	printf("%d����λ:\n",num);

	//ע�� i=i-2
	for (i = 0; i < 31; i += 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");

	printf("%dż��λ:\n", num);
	for (i = 1; i <= 31; i += 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	return 0;
}