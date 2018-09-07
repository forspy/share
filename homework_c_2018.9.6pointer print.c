#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void num_print(char* p, int size);
int main()
{
	char num[100];
	scanf("%s", num);
	num_print(num, strlen(num));
}

void num_print(char* p, int size)
{
	for (int i = 0; i < size; i++,p++)
	{
		printf("%c", *p);
		printf(" ");
	}
	printf("\n");
}