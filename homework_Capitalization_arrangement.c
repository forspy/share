#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char str1[] = "ABDEF";
	char str2[] = "abcdef";
	char together[100] = { 0 };
	int temp;
	for (int i = 0; i < 6; i++)
	{
		temp = -1;//将位置初始化
		
		for (int j = 0; j < 5; j++)
		{
			if ((str2[i] - 'a' + 'A')==str1[j])
			{
				temp = j;//找到匹配的位置
				break;
			}
		}

		if (temp != -1)
		{
			strncat(together, str1 + temp,1);
			strncat(together, str2 + i,1);
		}
		else
			strncat(together, str2 + i,1);
	}
	printf("%s\n", together);
}