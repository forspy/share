#include<stdio.h>

void revse_sort(char*, int);
int main(int agrc, char**agrv)
{
	printf("sizeof char=%d\n", sizeof(char));
	printf("sizeof short=%d\n", sizeof(short));
	printf("sizeof int=%d\n", sizeof(int));
	printf("sizeof long=%d\n", sizeof(long));
	printf("sizeof float=%d\n", sizeof(float));
	printf("sizeof double=%d\n", sizeof(double));
	
	int quotient;
	printf("请输入一个数\n");
	scanf("%d", &quotient);
	int souce_quotient = quotient;
	int remainder;
	char binary[20];
	int i = 0;
	//思路：将余数一个一个的存到char数组中，最后倒序输出
	while (quotient != 1)
	{
		remainder = quotient % 2;
		quotient = quotient / 2;
		binary[i] = (char)('0' + remainder);//整型int转化成字符型char的方法之一
		i++;
	}
	
	int num = i + 1;
	binary[num-1] = '1';
	revse_sort(binary, num);
	binary[num] = '\0';//注意截断，注意数组下标从0开始
	printf("十进制%d的二进制为%s\n", souce_quotient,binary);
}

void revse_sort(char *a, int num)
{
	int temp;
	for (int i = 0; i < num / 2; i++)
	{
		temp = a[i];
		a[i] = a[num - i - 1];
		a[num - i - 1] = temp;
	}
}