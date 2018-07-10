// basic test_print longest text line.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#define MAXLINE 1000 //定义int表示创建变量或者分配储存单元，而“声明”指的是说明变量的性质，但不分配存储单元
 int max;//在同一文件中放在函数前的外部变量extern可以省略，但是源程序下几个cpp文件的变量调用需要声明extern
 char line[MAXLINE], longest[MAXLINE];
//过分依赖外部变量会导致一定的风险，因为它会使得程序中的数据关系变得模糊不清-----外部变量的值可能会被不经意地修改，使得程序的修改变得十分困难
 //现在编写的这个版本就不如前一个版本好，一是使用了外部变量；另一个方面，此版本中的函数将他们所操纵的变量直接写入了函数
//从而使得这两个有用的函数失去了通用性
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
