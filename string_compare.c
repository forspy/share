#include<stdio.h>
int strcmp(char *s, char *t);
int strcmp1(char *s, char *t);
int strcmp2(char *s, char *t);
int main()
{
	char s[] = "helaa!";
	char t[] = "helAA!";
	int j;//不能将void类型的值分配到int类型的实体，函数void声明的值是不能传回调用函数的
	j = strcmp2(s, t);
	printf("%d",j);
}

int strcmp(char *s, char *t)
{
	int i;
	for (i = 0; s[i] == t[i]; i++)
	{
		if (s[i] == '\0')
			return 0;
	}
		return s[i] - t[i];
	
}

int strcmp1(char *s, char *t)
{
	while (*s++ == *t++);
	
	return *s - *t;
}
int strcmp2(char *s, char *t)
{
	for (; *s ==*t; s++, t++)
	//if (*s == '\0')//待解决！ 不是所有的控件路径都返回值
		//return 0;
	return *s - *t;
}
