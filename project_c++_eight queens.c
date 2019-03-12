#include<stdio.h>
#include<stdlib.h>

#define MAX 4
int queen[MAX], sum = 0;
void show()
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		printf("(%d,%d)", i, queen[i]);
	}
	printf("\n");
	sum++;
}

int check(int n)//检查当前行能否放皇后
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
		{
			return 1;//表示不能放
		}
	}
	return 0;
}

void put(int n)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		queen[n] = i;//n表示行，i表示列，从0列开始试
		if (!check(n))
		{
			if (n == MAX - 1)
				show();//如果是最后一个则输出
			else
				put(n + 1);//递归调用
		}
	}
}

int main()
{
	put(0);//从0开始输入
	printf("%d", sum);
}