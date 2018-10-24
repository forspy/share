#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

void init(struct queue* qu)
{
	qu->front = NULL;
	qu->rear = NULL;
}
//显示数据
void show(struct queue* qu)
{
	if (isempty(qu))
	{
		printf("队列为空\n");
		return ;
	}
	struct node* p = qu->front;
	//花式show（兼容循环队列写法）
	while (p != qu->rear)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	//需要在循环中打印最后一个元素
	printf("%d->NULL\n", p->data);
}
//获得队首元素
int get_front(struct queue* qu)
{
	if (isempty(qu))
	{
		printf("队列为空\n");
		return 0;
	}
	return qu->front->data;
}

//得到队列大小
int get_size(struct queue* qu)
{
	if (isempty(qu))
	{
		printf("队列为空\n");
		return 0;
	}
	int size = 1;
	struct node* p = qu->front;
	while (p != qu->rear)
	{
		p = p->next;
		size++;
	}
	return size;
}
//判断是否为空
int isempty(struct queue* qu)
{
	return !qu->front&&!qu->rear;//如果为队列为空返回1，有返回0
}
//申请节点
struct node*  creat_node(int data)
{
	struct node* p_new = (struct node*)malloc(sizeof(struct node));
	if (!p_new)
	{
		printf("申请节点失败\n");
		return NULL;
	}
	p_new->data = data;
	p_new->next = NULL;//链接NULL
	return p_new;//返回节点地址
}
//入队列
void push(struct queue* qu, int data)
{
	//链表尾插法
	struct node* p_new = creat_node(data);
	if (qu->rear)//至少有一个元素
	{
		qu->rear->next = p_new;
	}
	else//没有元素
	{
		qu->front = p_new;//给队首插入
	}
	qu->rear = p_new;//因为不是那种从头遍历的方式，所以需要移动尾指针指向链表的最后一个对象
}
//删除节点
struct node* del_node(struct node* node)
{
	struct node* temp = node->next;
	node->next = NULL;
	free(node);
	return temp;
}
//出队列
int pop(struct queue* qu)
{
	if (isempty(qu))//判断是否为空
	{
		return -1;
	}
	//弹出链表
	int data = qu->front->data;
	qu->front = del_node(qu->front);
	if (!qu->front)//当仅有的一个节点也删除了以后
	{
		qu->rear = NULL;//
	}
	return data;
}
