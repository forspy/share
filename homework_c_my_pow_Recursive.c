#include<stdio.h>
int my_pow(int n, int k);
int main(int argc,char* argv[])
{	
	int n, k;
	printf("请输入底数和幂\n");
	scanf("%d %d", &n, &k);
	printf("%d的%d次幂是%d\n", n, k, my_pow(n, k));
}

int my_pow(int n, int k)
{
	if (k == 0)
		return 1;
	else
	{
		return n*my_pow(n,k - 1);
	}
}