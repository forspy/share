#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"double linked list.h"
//˫������

int main()
{
	struct dlist list;
	init(&list);
	insert_end(&list, 1);
	insert_end(&list, 2);
	insert_end(&list, 3);
	//insert_head(&list, 4);
	//del_pos_v1(&list, 2);
	//del_head(&list);//ͷɾ��
	del_end(&list);//βɾ��
	//printf("%d\n",find_node(&list, 3));//����ֵ���ҽڵ�λ��
	show(&list);
}