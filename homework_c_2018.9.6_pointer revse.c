#include<stdio.h>
#include<string.h>
void revse_print(char* ptr,int size);
int main()
{
	
	char* p = "danny";
	revse_print(p+4,strlen(p));
	for (int i = 1; i > 0; --i)//i--��forѭ��һ��ĩβ--��--iҲ����ĩβ--������forѭ��������ѭ��ĩβ��i����
		printf("%d", i);
	printf("\n");
	int j = 1;
	while (j--)//j--�ڣ��������жϺ�--��--j�ڣ�������--���жϣ������ڣ�������ɣ�����for
		printf("%d", j);
	printf("\n");
}

void revse_print(char* ptr,int size)
{
	for (int i = size; i > 0; ptr--,i--)
		printf("%c",*ptr);
	printf("\n");
}
