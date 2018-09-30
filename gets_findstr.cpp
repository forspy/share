#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int findstr(char* source, char* searchfor);
int main()
{
	char  str[2000] = { 0 };
	char a[1000];
	char b[1000];
	gets_s(a);//输入a字符串
	gets_s(b);//输入b字符串
	//连接a字符串
	strcat(str, a);
	strcat(str, a);
	//printf("%s\n", str);
	if (findstr(str, b))
		printf("true\n");
	else
		printf("false\n");
}
int findstr(char* source, char* searchfor)
{
	int i, j, k;
	for (i = 0; source[i] != '\0'; i++)
	{
		for (j = i, k = 0; source[j] == searchfor[k] && searchfor[k] != '\0'; j++, k++)
			;
		if (searchfor[k] == '\0'&&k > 0)
			return 1;//相当于跳出/
	}
	return 0;
}