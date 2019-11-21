// basic test_print longest text line.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#define MAXLINE 1000

int getline(char* line, int maxline);//将一行读入，并返回长度；[]表示动态分配字符串长度
void copy(char* to, char* from);//用于复制最大输入行

int main()
{
	int num = 0;//用于跳出
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	{
		num++;

		if (len > max)
		{
			max = len;
			copy(longest, line);
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

int getline(char* s, int* lim)//s为数组，指针传入地址，对该地址的内存进行操作
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF&&c != '\n'; ++i)
	{
		s[i] = c;
	}
		if (c == '\n')
		{
			s[i] = c;
			++i;
		}
		s[i] = '\0';
	
	return i;
}

void copy(char* to, char* from)
{
	int i;
	i = 0;
	while (to[i] = from[i])
		i++;
}
