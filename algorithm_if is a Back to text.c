#include <stdio.h>
#include<math.h>
int if_is_back_to_text(int num);
int main()
{
	int value ;
	printf("请输入一个数(int范围内)判断是不是回文\n");
	scanf("%d", &value);
	if (value == if_is_back_to_text(value))
		printf("%d是回文\n", value);
	else
		printf("%d不是回文\n", value);
	
}
//思路:返回一个倒序数字
int if_is_back_to_text(int num)
{
	int temp,sum;
	sum = 0;
	int bit_num[30];
	int i = 0;
	while (num > 0)
	{
		temp = num;
		num = num / 10;
		bit_num[i] =  temp - num * 10;
		i++;
	}
	i--;
	int mi;
	int j = 0;
	for (i; i >= 0; i--)
	{
		mi = (int)pow(10, j);
		sum = sum + bit_num[i] * mi;
		j++;
	}
	return sum;
}