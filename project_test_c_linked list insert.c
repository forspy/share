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
//在指定位置插入
void insert(int pos, int ID, int age, char* name);
//头删法
void del_node_head();
//尾删法
void del_node_end();
//改变值
void change(int ID, int value);
int main()
{
	init();
	append(1, 18, "joker");
	append(2, 19, "batman");
	append(3, 20, "riddle");
	append(4, 21, "Penguin");
	append(5, 22, "scarecrow");
	del_node_head();
	del_node_end();
	insert(4, 99, 99, "insert");//注意head算1，所以pos=4是插在3后面
	change(4, 99);
	show();
	printf("请输入要查找的学生ID号\n");
	int num;
	scanf("%d", &num);
	search(num);
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
	while (p->next)
	{
		p = p->next;
	}
	p->next = newnode;
}
void insert(int pos, int ID, int age, char* name)
{
	//1.判断pos是否正确
	struct student* p = &head;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
		if (p==NULL)
		{
			printf("pos超出范围\n");
			break;
		}
	}
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
	
	newnode->next = p->next;
	p->next = newnode;
}
//
void del_node_head()//头删法
{
	struct student* pn = (&head)->next;
	if (pn)
	{
		(&head)->next = pn->next;
		free(pn);//释放删除节点
	}
	else
		printf("只有一个head头节点\n");
}
//尾删法
void del_node_end()
{
	struct student* p = &head;
	if (p->next)
	{
		while (p->next->next)
		{
			p = p->next;
		}
		p->next = NULL;
		free(p->next);//指到尾部节点free最后一个节点就行
	}
	else
		printf("只有一个头节点\n");
}
//指定位置删除节点

//改变指定ID处的值
void change(int ID, int value)
{
	struct student* p = &head;
	while (p->next)
	{
		p = p->next;
		if (p->ID == ID)
		{
			p->age = value;
			return;
		}
	}
	printf("没有找到该信息\n");
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
	printf("没有找到该信息\n");
}