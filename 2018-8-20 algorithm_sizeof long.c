#include<stdio.h>
//���ģ�ָ��
int main()
{
	long a[] = { 1,2 };
	int* p = a;
	printf("��������long�Ĵ�СΪ%dλ\n", (int)(p + 1)*8 - (int)(p)*8);
}