#include<stdio.h>
#include<stdlib.h>
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
	system("pause");
}