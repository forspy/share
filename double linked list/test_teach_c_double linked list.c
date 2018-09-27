#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"double linked list.h"
//双向链表

//定义一个指向链表开始的指针

int main()
{
	struct dlist list;
	init(&list);
	insert_end(&list, 1);
	insert_end(&list, 2);
	insert_end(&list, 3);
	insert_head(&list, 4);
	//del_pos_v1(&list, 2);
	del_head(&list);
	printf("%d\n",find_node(&list, 3));
	show(&list);
}