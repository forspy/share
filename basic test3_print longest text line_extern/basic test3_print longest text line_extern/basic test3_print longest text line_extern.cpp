// basic test_print longest text line.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#define MAXLINE 1000
int max;
char line[MAXLINE], longest[MAXLINE];
int getline(void);//��һ�ж��룬�����س��ȣ�[]��ʾ��̬�����ַ�������
void copy(void);//���ڸ������������

int main()
{
	int num = 0;//��������
    int len;
	extern int max;//�����ⲿ��ȫ�֣�������Ҫ��extern����
	extern char longest[];
	max = 0;
	while ((len = getline()) > 0)
	{
		num++;

		if (len > max)
		{
			max = len;
			copy();
		}
		if (num > 10)
		{
			break;
		}
	}
	if (max > 0)
		printf("%s", longest);

	return 0;
}

int getline(void)//sΪ����
{
	int c, i;
	extern char line[];
	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF&&c != '\n'; ++i)
	{
		line[i] = c;
	}
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i;
}

void copy(void)
{
	extern char line[], longest[];
	int i;
	i = 0;
	while ((longest[i]=line[i])!='\0')
		i++;
}