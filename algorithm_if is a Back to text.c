#include <stdio.h>
#include<math.h>
int if_is_back_to_text(int num);
int main()
{
	int value ;
	printf("������һ����(int��Χ��)�ж��ǲ��ǻ���\n");
	scanf("%d", &value);
	if (value == if_is_back_to_text(value))
		printf("%d�ǻ���\n", value);
	else
		printf("%d���ǻ���\n", value);
	
}
//˼·:����һ����������
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