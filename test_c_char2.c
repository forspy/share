#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char a[] = "hello";
	char* p = a;
	p[1] = 'p';
	char* ptr = "hello";
	//ptr[1] = 'p';�����ǲ��еģ���Ϊ"hello"�����ڳ�������ֻ����

	printf("%d\n", strcmp("aa", "AA"));
	printf("%d\n", strcmp("Aaa", "aA"));//strcmpֻ����Ƚ�
	char d[20] = "GoldenGlobal"; 
	char *s = "View"; 
	strcat(d, s);//1.d���������� 2.d����ָ�������С������d+s���ܳ���d����Ĵ�С
	printf("%s", d);
	

	char text[200] = { 0 };
	printf("�������ַ���\n");
	gets_s(text,100);//gets�������Խ������д��ջ�ѣ�����ϵͳ©����bug������gets_sָ�������С����ȫ
	printf("%s\n", text);
	/*strchr��һ���ַ����в����ַ���
	strstr��һ���ַ����в����ַ���
	strset��һ���ַ���ȫ�����ó�ĳ���ַ�*/
}