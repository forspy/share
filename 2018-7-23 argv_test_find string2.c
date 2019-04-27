
#include<stdio.h>
#include<string.h>
#define MAXLINE 10000

int getline(char line[], int max);

/*find函数：打印与第一个参数指定的模式匹配的行*/
main(int argc, int *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage:find pattern\n");
	else
	{
		while (getline(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL)
			{
				printf("%s", line);
				found++;
			}
	}
	return found;
}


/*getline:将输入字符串存储在s中，并返回输入字符串的长度*/
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
//进入cmd后，进入路径下输入："argv_test_find string2.exe" a（注意只有一个参数），功能：打印出含有参数名的字符行
//由于main函数不能被其它函数调用， 因此不可能在程序内部取得实际值。那么，在何处把实参值赋予main函数的形参呢? 
//实际上,main函数的参数值是从操作系统命令行上获得的。当我们要运行一个可执行文件时，在DOS提示符下键入文件名，
//再输入实际参数即可把这些实参传送到main的形参中去。