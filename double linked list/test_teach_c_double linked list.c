#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"double linked list.h"
//˫������

//����һ��ָ������ʼ��ָ��

int main()
{
	struct dlist list;
	init(&list);

	int x = getsize(&list);//����
	printf("%d\n", x);//����

	show(&list);
}