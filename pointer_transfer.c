#include <stdio.h>

void strcpy1(char *s, char *t);
void strcpy(char *s, char *t);
void strcpy2(char *s, char *t);
int main()
{
	char s[] = "hello";
	char t[] = "hello world";
	strcpy2(s, t);//1.在char t[] = "world!";char s[] = "hello world!";的时候，显示world，即短内存付给长内存
	//当长内存赋值给短内存的时候，短内存字符串长度不够，指针移到尾部后不能再移动
	printf("%s", s);
}

void strcpy1(char *s, char *t)
{
	int i;
	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0')
	{
		s++;
		t++;
		
	}
}

void strcpy2(char*s, char *t)
{
	while (*s++, *t++);
}