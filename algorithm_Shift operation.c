#include <stdio.h>

int main(int agrc, char** argv)
{
	int value;
	printf("������һ�����ж��ǲ���2����������\n");
	scanf("%d", &value);
	int count = 0;
	//���������ж��м���1����1����ԵĽ���ۼӵ�count���ж�count
	count = is_2intpower(value);
	
	if (count < 2)
		printf("%d��2����������\n",value);
	else
		printf("%d����2����������\n",value);
}

int is_2intpower(int number)
{
	int i=0;
	while (number)
	{
		i += number & 1;//����һλ�Ժ���Ȼ�ܱ�2����
		number >>= 1;
	}
	return i;
}