#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

void init(struct queue* qu)
{
	qu->front = NULL;
	qu->rear = NULL;
}
//��ʾ����
void show(struct queue* qu)
{
	if (isempty(qu))
	{
		printf("����Ϊ��\n");
		return ;
	}
	struct node* p = qu->front;
	//��ʽshow������ѭ������д����
	while (p != qu->rear)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	//��Ҫ��ѭ���д�ӡ���һ��Ԫ��
	printf("%d->NULL\n", p->data);
}
//��ö���Ԫ��
int get_front(struct queue* qu)
{
	if (isempty(qu))
	{
		printf("����Ϊ��\n");
		return 0;
	}
	return qu->front->data;
}

//�õ����д�С
int get_size(struct queue* qu)
{
	if (isempty(qu))
	{
		printf("����Ϊ��\n");
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
//�ж��Ƿ�Ϊ��
int isempty(struct queue* qu)
{
	return !qu->front&&!qu->rear;//���Ϊ����Ϊ�շ���1���з���0
}
//����ڵ�
struct node*  creat_node(int data)
{
	struct node* p_new = (struct node*)malloc(sizeof(struct node));
	if (!p_new)
	{
		printf("����ڵ�ʧ��\n");
		return NULL;
	}
	p_new->data = data;
	p_new->next = NULL;//����NULL
	return p_new;//���ؽڵ��ַ
}
//�����
void push(struct queue* qu, int data)
{
	//����β�巨
	struct node* p_new = creat_node(data);
	if (qu->rear)//������һ��Ԫ��
	{
		qu->rear->next = p_new;
	}
	else//û��Ԫ��
	{
		qu->front = p_new;//�����ײ���
	}
	qu->rear = p_new;
}
//ɾ���ڵ�
struct node* del_node(struct node* node)
{
	struct node* temp = node->next;
	node->next = NULL;
	free(node);
	return temp;
}
//������
int pop(struct queue* qu)
{
	if (isempty(qu))//�ж��Ƿ�Ϊ��
	{
		return -1;
	}
	//��������
	int data = qu->front->data;
	qu->front = del_node(qu->front);
	if (!qu->front)//�����е�һ���ڵ�Ҳɾ�����Ժ�
	{
		qu->rear = NULL;//
	}
	return data;
}
