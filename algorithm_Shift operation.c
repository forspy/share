#include <stdio.h>

int main(int agrc, char** argv)
{
	int value;
	printf("请输入一个数判断是不是2的整数次幂\n");
	scanf("%d", &value);
	int count = 0;
	//核心是判判断有几个1，与1与可以的结果累加到count，判断count
	count = is_2intpower(value);
	
	if (count < 2)
		printf("%d是2的整数次幂\n",value);
	else
		printf("%d不是2的整数次幂\n",value);
}

int is_2intpower(int number)
{
	int i=0;
	while (number)
	{
		i += number & 1;//右移一位以后任然能被2整除
		number >>= 1;
	}
	return i;
}