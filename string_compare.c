#include<stdio.h>
int strcmp(char *s, char *t);
int strcmp1(char *s, char *t);
int strcmp2(char *s, char *t);
int main()
{
	char s[] = "helaa!";
	char t[] = "helAA!";
	int j;//���ܽ�void���͵�ֵ���䵽int���͵�ʵ�壬����void������ֵ�ǲ��ܴ��ص��ú�����
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
	while (*s == *t);
	{
		s++;
		t++;
	}
	return *s - *t;
}
int strcmp2(char *s, char *t)
{
	for (; *s ==*t; s++, t++)
	//if (*s == '\0')//������� �������еĿؼ�·��������ֵ
		//return 0;
	return *s - *t;
}