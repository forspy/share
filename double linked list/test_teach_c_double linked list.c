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
	insert_end(&list, 1);
	insert_end(&list, 2);
	insert_end(&list, 3);
	del_pos_v1(&list, 2);
	show(&list);
}