#include <stdio.h>

typedef struct result
{
	int count;//用于计数
	bool flag;//用于判断
}result;

result is_2intpower(int number);

int main(int agrc, char** argv)
{
	int value;
	printf("请输入一个数判断是不是2的整数次幂\n");
	scanf("%d", &value);
	//核心是判判断有几个1，与1与可以的结果累加到count，判断count
	result status = is_2intpower(value);

	if (status.count >0 &&status.flag==true)
		printf("%d是2的%d次幂\n", value,status.count);
	else
		printf("%d不是2的整数次幂\n", value);
}

result is_2intpower(int number)//返回一个结构体，两个参数
{
	result status = {0,true};
	int temp;
	while (number>1)
	{
		temp = number & 1;
		if(temp==0)
		{
			status.count++;
			number >>= 1;
		}
		else
		{
			status.flag = false;
			break;
		}
	}
	return status;
}
