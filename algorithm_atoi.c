#include<stdio.h>
#include<ctype.h>

int main()
{
	char s[10] = "a b c d";//用字符串数组保存
	char *m;//用指针保存
	char n[10];
	n[8] = "a b c d";//表达式使用的值就是这些字符所存储的地址（在常量区），而不是这些字符本身。

	//所以，可以把字符串赋值给指向字符的指针p，而不能把字符串赋值给一个字符数组。
	m = "a b c c";
	//n = "abc";//一般来说对字符串赋值需要用到指针
	///s[10] = 'ab c d';
	printf("%s\n%s\n%s\n", s,m,n);
}