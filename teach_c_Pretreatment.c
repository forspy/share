#define  _CRT_SECURE_NO_WARNINGS
/*
Ԥ����
1.��#��ͷ������
a.�ļ�����
#include<stdio.h>��vsͷ�ļ��⿪ʼ���ң����û�ҵ������ʧ��
#include"test.h"�ӵ�ǰĿ¼��ʼ���ң����û�ҵ�ȥvsͷ�ļ�������
b.���滻 �ı��滻
�ú��ʾ�����ֵ �磺pi
C���������������С 
�磺
#define SIZE
char name[SIZE];
���ú����
 __LINE__ ��ʾ��ǰ��(����Ҫ#define )
 __FILE__ ��ʾ��ǰ·��
 __DATE__ ����ʱ������
 __TIME__ ����ʱ��ʱ��

 �꺯��
 #define ADD(X,Y) X+Y
c.��������
#if
#endif

#ifdef TEST
#endif
*/
#include<stdio.h>
#define MULTIPLY(X,Y) X*Y//�����ʾ�� ֻ�ǵ������滻
#define MY_MULTIPLY(X,Y) (X)*(Y)//�����������������׼ȷ
#define PI 3.1415926
#define HI 2
#define HELLO
int main()
{
	printf("%d\n", __LINE__);
	printf("%s\n", __FILE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	char buf[128] = { 0 };
	sprintf(buf, "�ļ�%s:%d\n",__FILE__, __LINE__);//��ʽ�����룬��char��int�ϲ���char����buf��
	printf("%s", buf);
	int x = MULTIPLY(10 - 1, 10 - 1);
	printf("%d\n", x); //�൱�� 10-1*10-1=-1
	int x1 = MY_MULTIPLY(10 - 1, 10 - 1);
	printf("%d\n", x1); //�൱�� 10-1*10-1=-1
	int m = 1;
#if HI//�����ǲ��еģ���ΪԤ������ִ�У������ִ��
	printf("OK\n");
#endif

#ifdef HELLO
	printf("hello\n");
#endif
	//��ֹ�ظ�����
#ifndef __TEST_H__
#define __TEST_H__
	printf("test\n");
#endif
	//ctrl+c��ctrl+z�����ж����� ����alt+F4
#undef PI //ȡ���궨��
	//���ļ�����#pragma comment (lib,"xxx.lib")
//#pragma warning
}
