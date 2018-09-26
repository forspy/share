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

	int x = getsize(&list);//测试
	printf("%d\n", x);//测试

	show(&list);
}