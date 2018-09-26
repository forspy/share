#include"double linked list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init(struct dlist* list)
{
	list->p_head = NULL;
	list->p_end = NULL;
}

//数据用malloc开辟内存
struct node* creat_data(int data,struct node* next,struct node* prv)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));//开辟一个节点内存
	if (!p)
	{
		printf("申请节点失败\n");
		return NULL;
	}
	p->ID = data;
	p->next = next;
	p->prv = prv;
	return p;
}

//如果没有节点
int isempty(struct dlist* list)
{
	return !(list->p_head) && !(list->p_end);//链表没有节点返回1，有节点返回0
}
//返回节点个数
int getsize(struct dlist* list)
{
	if (isempty(list))
	{
		printf("链表为空\n");
		return 0;
	}
	int size=0;
	struct node* p = list->p_end;

		//加入从后往前找
	while (p)
	{
		p = p->prv;
		size++;
	}
	return size;
}
//遍历显示节点内容
void show(struct dlist* list)
{
	if (isempty(list))
	{
		printf("链表为空\n");
		return;
	}
	struct node* p = list->p_head;
	//从头部往下遍历
	while (p)
	{
		printf("%d<->", p->ID);
		p = p->next;
	}
}

//尾插法
int insert_end(struct dlist* list,int data)
{
	if (isempty(list))
	{
		printf("链表为空\n");
		return 0;
	}
	struct node* p = list->p_end;
	//先移动p_end再链接
	list->p_end=creat_data(data,NULL,list->p_end);//将p_end指针移向新节点
	
	if (list->p_end->prv)
	{
		list->p_end->prv->next = list->p_end;
	}
	else
	{
		printf("只有一个节点\n");
		list->p_head = list->p_end;//只有一个节点的话
	}
	//待测试
	/*
	//先链再移动p_end
	list->p_end->next = creat_data(data, NULL, list->p_end);
	list->p_end = list->p_end->next;
	*/
	
}
//删除一个节点，返回下一个节点指针
struct node* delete_node(struct node* node,struct node** prv)
{
	struct node* temp = node->next;
	*prv = node->prv;//链上上一个
}

//指定位置删除
void del_pos(struct dlist* list, int pos)
{
	struct node* p = list->p_head;
	//prv前节点 next后节点
	for(;)
}