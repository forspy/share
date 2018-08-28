#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char a[] = "hello";
	char* p = a;
	p[1] = 'p';
	char* ptr = "hello";
	//ptr[1] = 'p';这样是不行的，因为"hello"设置在常量区是只读的

	printf("%d\n", strcmp("aa", "AA"));
	printf("%d\n", strcmp("Aaa", "aA"));//strcmp只逐个比较
	char d[20] = "GoldenGlobal"; 
	char *s = "View"; 
	strcat(d, s);//1.d必须是数组 2.d必须指明数组大小，并且d+s不能超过d定义的大小
	printf("%s", d);
	

	char text[200] = { 0 };
	printf("请输入字符串\n");
	gets_s(text,100);//gets函数可以将溢出的写入栈堆，存在系统漏洞和bug，利用gets_s指明输入大小更安全
	printf("%s\n", text);
	/*strchr在一个字符串中查找字符串
	strstr在一个字符串中查找字符串
	strset将一个字符串全部设置成某个字符*/
}