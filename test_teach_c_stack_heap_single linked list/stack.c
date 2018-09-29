#include<stdio.h>
#include"stack.h"
#include<stdlib.h>
//��ʼ��
void init(struct stack* st)
{
	st->top = NULL;
}

//�ж�ջ�������Ƿ�Ϊ�գ����Ϊ�շ���1��
int isempty(struct stack* st)
{
	return !st->top;
}
//��ʾջ������Ԫ��
void show(struct stack* st)
{
	if (isempty(st))
	{
		printf("ջΪ��\n");
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

//�õ�ջ��Ԫ��
int get_top(struct stack* st)
{
	if (isempty(st))
	{
		printf("ջΪ��\n");
		return 0;
	}
	else
	{
		return st->top->data;
	}
}

//�õ�ջ�Ĵ�С
int getsize(struct stack* st)
{
	if (isempty(st))
	{
		printf("ջΪ��\n");
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
	//����
}
//�����ڵ㣬�������½��ڵ����һ���ڵ�
struct node* creat_node(int data, struct node* p_next)//�������ݺ�������һ���ڵ�
{
	struct node* p_new = (struct node*)malloc(sizeof(struct node));
	if (!p_new)
	{
		printf("û���㹻�ڴ棬�����ڵ�ʧ��\n");
		return NULL;
	}
	p_new->data = data;
	p_new->next = p_next;
	return p_new;
}
//ѹջ���������ݣ�,ͷ���������+�ƶ�top
void push(struct stack* st, int data)
{
	//��top�ƶ�
	st->top = creat_node(data, st->top);
}
//ɾ��һ���ڵ㣬������һ�����
struct node* del_node(struct node* node)
{
	struct node* temp = node->next;
	node->next = NULL;
	free(node);
	return temp;
}

//��ջ
int pop(struct stack* st)
{
	if (isempty(st))
	{
		printf("��ջ����ɾ��\n");
		return 0;
	}
	int temp = st->top->data;
	st->top = del_node(st->top);
	return temp;
}

//ջ���
void pop_all(struct stack* st)
{
	while (st->top)
	{
		st->top = del_node(st->top);
	}
}