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
		printf("char����%c��intֵΪ%d\n", arr[i], (int)arr[i]);//��charֱ��ת����int��int��Ҫ��-'0'��ת����char��
}