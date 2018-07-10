// basic test_print longest text line.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#define MAXLINE 1000
int max;
char line[MAXLINE], longest[MAXLINE];
int getline(void);//将一行读入，并返回长度；[]表示动态分配字符串长度
void copy(void);//用于复制最大输入行

int main()
{
	int num = 0;//用于跳出
    int len;
	extern int max;//调用外部（全局）变量需要用extern命令
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

int getline(void)//s为数组
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