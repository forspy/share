#include<stdio.h>
#include<string.h>

void Capitalization_change(char* src, int len);//��Сдת������汾
int main()
{
	char str[20] ;
	printf("������һ���ַ���\n");
	gets_s(str,19);//scanf��֧������ո�
	printf("ԭ�ַ���  %s\n", str);
	Capitalization_change(str, strlen(str));
	printf("��Сдת��%s\n", str);
}

void Capitalization_change(char* src, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (src[i] >= 'A' && src[i] <= 'Z')//'A'����
		{
			src[i] = src[i] + 'a' - 'A';
		}
	}
}