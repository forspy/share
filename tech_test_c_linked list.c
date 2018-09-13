#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node//节点
{
	int data;
	struct node* next;//指向下一个节点
};

typedef struct node node;
typedef struct node* pnode;

struct node head;//链表头
		  //pnode p_head = &head;//定义一个指向头的指针
struct node* p_head = &head;
void append(int DATA);
void show();
int main()
{
	append(10);
	append(20);
	append(30);
	show();
}

void init()//初始化
{
	p_head->data = 0;
	p_head->next = NULL;
}

void append(int DATA)//尾插法
{
	//1.申请节点
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	//如果内存不够，返回
	if (!newnode)
	{
		printf("申请内存失败\n");
		return;
	}
	//2.赋值
	newnode->data = DATA;
	newnode->next = NULL;//注意新插入的节点
	//3.链接
	//p_head->next = newnode;
	//找到最后一个节点
	struct node* p = p_head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = newnode;
}
void show()
{
	struct node* p = p_head;
	while (p->next)
	{
		p = p->next;
		printf("%d\n", p->data);
	}
}