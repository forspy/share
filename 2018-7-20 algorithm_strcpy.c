#include <stdio.h>

void strcpy1(char *s, char *t);
void strcpy(char *s, char *t);
void strcpy2(char *s, char *t);
int main()
{
	char s[] = "hello";
	char t[] = "hello world";
	strcpy2(s, t);//1.��char t[] = "world!";char s[] = "hello world!";��ʱ����ʾworld�������ڴ渶�����ڴ�
	//�����ڴ渳ֵ�����ڴ��ʱ�򣬶��ڴ��ַ������Ȳ�����ָ���Ƶ�β���������ƶ�
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