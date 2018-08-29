#include<stdio.h>
#include<string.h>

void Capitalization_change(char* src, int len);//大小写转换精简版本
int main()
{
	char str[20] ;
	printf("请输入一行字符串\n");
	gets_s(str,19);//scanf不支持输入空格
	printf("原字符串  %s\n", str);
	Capitalization_change(str, strlen(str));
	printf("大小写转换%s\n", str);
}

void Capitalization_change(char* src, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (src[i] >= 'A' && src[i] <= 'Z')//'A'是数
		{
			src[i] = src[i] + 'a' - 'A';
		}
	}
}