#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	double* a[10] ;//ָ������
	double arr[3];
	double(*p)[3];//����ָ�룬ָ�������ָ��
	p = &arr;//&��ʾ��������ĵ�ַ
	printf("%p %p\n", p, p + 1);//00C4F9D0 00C4F9E8 ��24
	char* ptr = (char*)malloc(sizeof(char) * 100);
	//p = "hello";//�����Ͷ�ʧ��ָ��ѵ��ڴ棬������ڴ�й©
	strcpy(ptr, "hello");//�����Ϳ��Է���ضԶѲ���
	free(ptr);
}