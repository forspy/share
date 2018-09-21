#define  _CRT_SECURE_NO_WARNINGS
/*
预处理：
1.以#开头的内容
a.文件包含
#include<stdio.h>从vs头文件库开始查找，如果没找到则包含失败
#include"test.h"从当前目录开始查找，如果没找到去vs头文件库中找
b.宏替换 文本替换
用宏表示方便的值 如：pi
C语言中用于数组大小 
如：
#define SIZE
char name[SIZE];
常用宏命令：
 __LINE__ 表示当前行(不需要#define )
 __FILE__ 表示当前路径
 __DATE__ 编译时的日期
 __TIME__ 编译时的时间

 宏函数
 #define ADD(X,Y) X+Y
c.条件编译
#if
#endif

#ifdef TEST
#endif
*/
#include<stdio.h>
#define MULTIPLY(X,Y) X*Y//错误的示范 只是单纯的替换
#define MY_MULTIPLY(X,Y) (X)*(Y)//所以用括号括起变量准确
#define PI 3.1415926
#define HI 2
#define HELLO
int main()
{
	printf("%d\n", __LINE__);
	printf("%s\n", __FILE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	char buf[128] = { 0 };
	sprintf(buf, "文件%s:%d\n",__FILE__, __LINE__);//格式化输入，将char和int合并成char输入buf中
	printf("%s", buf);
	int x = MULTIPLY(10 - 1, 10 - 1);
	printf("%d\n", x); //相当于 10-1*10-1=-1
	int x1 = MY_MULTIPLY(10 - 1, 10 - 1);
	printf("%d\n", x1); //相当于 10-1*10-1=-1
	int m = 1;
#if HI//这样是不行的，因为预编译先执行，定义后执行
	printf("OK\n");
#endif

#ifdef HELLO
	printf("hello\n");
#endif
	//防止重复包含
#ifndef __TEST_H__
#define __TEST_H__
	printf("test\n");
#endif
	//ctrl+c和ctrl+z都是中断命令 还有alt+F4
#undef PI //取消宏定义
	//库文件包含#pragma comment (lib,"xxx.lib")
//#pragma warning
}
