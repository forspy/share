#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int ID;
	int age;
	char* name;
	struct student* next;//指向下一个节点
};
//定义一个链表头
struct student head;
//初始化
void init();
//插入信息
void append(int ID, int age, char* name);
//显示所有信息
void show();
//提供查找功能
void search(int ID);
int main()
{
	init();
	append(1, 123, "joker");
	append(2, 110, "batman");
	show();
	printf("头插法插入一个数据\n");
	append(3, 666, "Penguin");
	show();
	free(head.next);//释放堆上内存
}
//初始化
void init()
{
	head.ID = 0;
	head.age = 0;
	head.name = NULL;
	head.next = NULL;
}
//插入信息
void append(int ID, int age, char* name)
{
	//1.申请节点
	struct student* newnode = (struct student*)malloc(sizeof(struct student));
	//如果内存不够，返回
	if (!newnode)
		return;
	//2.对节点赋值
	newnode->ID = ID;
	newnode->age = age;
	newnode->name = name;
	newnode->next = NULL;//节点尾部赋值NULL
						 //3.链接（尾插法）
	struct student* p = &head;//先让待移动的指针指向头部
	newnode->next = p->next;//先把head的next指向赋值给newnode的next
	p->next = newnode;//再把newnode赋值给head的next
}
//显示所有信息
void show()
{
	struct student* p = &head;
	while (p->next)
	{
		p = p->next;
		printf("%d \n", p->age);
	}
}
//提供查找功能
void search(int ID)
{
	struct student* p = &head;
	while (p->next)
	{
		p = p->next;
		if (p->ID == ID)
		{
			printf("ID=%d age=%d name=%s\n", p->ID, p->age, p->name);
			return;
		}
	}
}