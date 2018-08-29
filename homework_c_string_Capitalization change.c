#include<stdio.h>
#include<string.h>
//大小写转换原始版本
void Capitalization_change(char src[], int len);
int main()
{
	char str[20] = "HelloWorld!";
	Capitalization_change(str, strlen(str));
	printf("%s\n", str);
}

void Capitalization_change(char src[],int len)
{
	for (int i = 0; i < len; i++)
	{
		if ((int)(src[i]) >= 41 && (int)(src[i]) <= 90)
		{
			src[i] = (char)((int)(src[i]) + 97 - 65);
		}
	}
}