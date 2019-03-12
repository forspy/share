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

int check(int n)//��鵱ǰ���ܷ�Żʺ�
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
		{
			return 1;//��ʾ���ܷ�
		}
	}
	return 0;
}

void put(int n)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		queen[n] = i;//n��ʾ�У�i��ʾ�У���0�п�ʼ��
		if (!check(n))
		{
			if (n == MAX - 1)
				show();//��������һ�������
			else
				put(n + 1);//�ݹ����
		}
	}
}

int main()
{
	put(0);//��0��ʼ����
	printf("%d", sum);
}