#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	char arr[10];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 10 + 48;
	}
	for (int i = 0; i < 10; i++)
		printf("char类型%c的int值为%d\n", arr[i], (int)arr[i]);//将char直接转化成int（int需要先-'0'再转化成char）
}