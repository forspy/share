#include<stdio.h>
#include"stack.h"
#include<stdlib.h>
//初始化
void init(struct stack* st)
{
	st->top = NULL;
}

//判断栈（链表）是否为空（如果为空返回1）
int isempty(struct stack* st)
{
	return !st->top;
}
//显示栈上链表元素
void show(struct stack* st)
{
	if (isempty(st))
	{
		printf("栈为空\n");
		return;
	}
	struct node* p = st->top;
	
	while (p)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("\n");
}

//得到栈顶元素
int get_top(struct stack* st)
{
	if (isempty(st))
	{
		printf("栈为空\n");
		return 0;
	}
	else
	{
		return st->top->data;
	}
}

//得到栈的大小
int getsize(struct stack* st)
{
	if (isempty(st))
	{
		printf("栈为空\n");
		return 0;
	}
	int size = 0;
	struct node* p = st->top;
	
	while (p)
	{
		p = p->next;
		size++;
	}
	return size;
	//待续
}
//创建节点，并链接新建节点的下一个节点
struct node* creat_node(int data, struct node* p_next)//输入数据和链接下一个节点
{
	struct node* p_new = (struct node*)malloc(sizeof(struct node));
	if (!p_new)
	{
		printf("没有足够内存，创建节点失败\n");
		return NULL;
	}
	p_new->data = data;
	p_new->next = p_next;
	return p_new;
}
//压栈（存入数据）,头部链表插入+移动top
void push(struct stack* st, int data)
{
	//将top移动
	st->top = creat_node(data, st->top);
}
//删除一个节点，返回下一个结点
struct node* del_node(struct node* node)
{
	struct node* temp = node->next;
	node->next = NULL;
	free(node);
	return temp;
}

//出栈
int pop(struct stack* st)
{
	if (isempty(st))
	{
		printf("空栈不能删除\n");
		return 0;
	}
	int temp = st->top->data;
	st->top = del_node(st->top);
	return temp;
}

//栈清空
void pop_all(struct stack* st)
{
	while (st->top)
	{
		st->top = del_node(st->top);
	}
}