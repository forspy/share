#include<stdio.h>
#include<stdlib.h>
void fun1(void);
void fun2(void);
int main(int argc, char* argv[])
{
	//agrc:��������ĸ�����Ĭ��1����ʼ
	//agrv[]ָ�����飨��һϵ���ַ�����ַ��
	for (int i = 0; i < argc; i++)
		printf("��%d��%s\n", i, argv[i]);
	printf("----------------\n");
	printf("agrc=%d\n", argc);
	//����һ��cmd ��.exe·���ո���������ո��������...
	//��������shiftѡ�����ļ�������.exe�ļ���
	//����������Ŀ����-��������-����-�������������������ÿո����
	atexit(fun1);
	atexit(fun2);//atexit������ʾ��main���������Ժ��ٵ��ã��ȵ�fun2���ٵ�fun1���������ϵ���
	system("pause");
}
void fun1(void)
{
	printf("1\n");
}
void fun2(void)
{
	printf("2\n");
}