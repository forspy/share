#include<stdio.h>
#include<stdlib.h>
void fun1(void);
void fun2(void);
int main(int argc, char* argv[])
{
	//agrc:传入参数的个数，默认1个开始
	//agrv[]指针数组（存一系列字符串地址）
	for (int i = 0; i < argc; i++)
		printf("第%d个%s\n", i, argv[i]);
	printf("----------------\n");
	printf("agrc=%d\n", argc);
	//方法一：cmd 打开.exe路径空格输入参数空格输入参数...
	//方法二：shift选择多个文件，拖入.exe文件中
	//方法三：项目属性-配置属性-调试-命令参数里输入参数，用空格隔开
	atexit(fun1);
	atexit(fun2);//atexit函数表示在main函数结束以后再调用，先调fun2，再调fun1，从下往上调用
	system("pause");
}
void fun1(void)
{
	printf("1\n");
}
void fun2(void)
{
	printf("2\n");
}