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
	append(1, 18, "joker");
	append(2, 19, "batman");
	append(3, 20, "riddle");
	append(4, 21, "Penguin");
	append(5, 22, "scarecrow");
	//show();
	printf("请输入要查找的学生ID号\n");
	int num;
	scanf("%d", &num);
	search(num);
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
void append(int ID,int age,char* name)
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
	while (p->next)
	{
		p = p->next;
	}
	p->next = newnode;
}
//显示所有信息
void show()
{
	struct student* p = &head;
	while (p->next)
	{
		p = p->next;
		printf("ID=%d age=%d name=%s\n", p->ID, p->age, p->name);
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