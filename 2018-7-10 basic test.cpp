// Win32Project4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

int main()
{
	int m=1;
	float n=3.2,k;
	int i, j;
	k = m + n;
	for (i = j = 0; i <= 10; i++)//i=j=0相当于i=0,j=0;且不会重复对i，j赋值
	{
       printf("%d, %d\n", i, j);
	}
	printf("%f", k);
		
    return 0;
}

//类型，运算符与表达式
//int 32位 4字节
//float 单精度浮点型 4字节
//double 双精度浮点型 8字节
//short int 短整型 16
//long int 长整形 如12345L
//介绍一些小函数
//标准库函数strlen(s) 返回字符串参数s的长度（头文件<string.h>）
//enum 变量类{小变量1，小变量2...}没有指定则递增生成（小变量1的值要指定）
//const 类型 变量;const修饰的变量值不能改变
//！将非0变为0，将0变为1 如：if(!valid)
//char类其实是较小的整形因此ASCII字符可以相加减 如c+'a'-'A'可以实现大写转换成小写 如tolower()函数<cytpe.h>
//unsigned无符号变量signed符号变量
//long+double=double int+float=float
//一些函数会自动将参数转换类型，如sqrt(double),伪随机函数rand
//自增/自减运算符，s[j++]=1;-->s[j]=1;j++;
//赋值运算i=i+2;-->i+=2;x*=y+1;-->x=x*(y+1);
//条件表达式 z=(a>b)?a:b;