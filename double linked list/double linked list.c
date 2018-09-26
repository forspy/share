#include"double linked list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init(struct dlist* list)
{
	list->p_head = NULL;
	list->p_end = NULL;
}

//������malloc�����ڴ�
struct node* creat_data(int data,struct node* next,struct node* prv)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));//����һ���ڵ��ڴ�
	if (!p)
	{
		printf("����ڵ�ʧ��\n");
		return NULL;
	}
	p->ID = data;
	p->next = next;
	p->prv = prv;
	return p;
}

//���û�нڵ�
int isempty(struct dlist* list)
{
	return !(list->p_head) && !(list->p_end);//����û�нڵ㷵��1���нڵ㷵��0
}
//���ؽڵ����
int getsize(struct dlist* list)
{
	if (isempty(list))
	{
		printf("����Ϊ��\n");
		return 0;
	}
	int size=0;
	struct node* p = list->p_end;

		//����Ӻ���ǰ��
	while (p)
	{
		p = p->prv;
		size++;
	}
	return size;
}
//������ʾ�ڵ�����
void show(struct dlist* list)
{
	if (isempty(list))
	{
		printf("����Ϊ��\n");
		return;
	}
	struct node* p = list->p_head;
	//��ͷ�����±���
	while (p)
	{
		printf("%d<->", p->ID);
		p = p->next;
	}
}

//β�巨
int insert_end(struct dlist* list,int data)
{
	if (isempty(list))
	{
		printf("����Ϊ��\n");
		return 0;
	}
	struct node* p = list->p_end;
	//���ƶ�p_end������
	list->p_end=creat_data(data,NULL,list->p_end);//��p_endָ�������½ڵ�
	
	if (list->p_end->prv)
	{
		list->p_end->prv->next = list->p_end;
	}
	else
	{
		printf("ֻ��һ���ڵ�\n");
		list->p_head = list->p_end;//ֻ��һ���ڵ�Ļ�
	}
	//������
	/*
	//�������ƶ�p_end
	list->p_end->next = creat_data(data, NULL, list->p_end);
	list->p_end = list->p_end->next;
	*/
	
}
//ɾ��һ���ڵ㣬������һ���ڵ�ָ��
struct node* delete_node(struct node* node,struct node** prv)
{
	struct node* temp = node->next;
	*prv = node->prv;//������һ��
}

//ָ��λ��ɾ��
void del_pos(struct dlist* list, int pos)
{
	struct node* p = list->p_head;
	//prvǰ�ڵ� next��ڵ�
	for(;)
}