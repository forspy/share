#pragma once
struct node
{
	int data;
	struct node* next;
};
//����Ϊ�˷�ֹ�޸�ȫ��ָ���ýṹ���װ
struct stack
{
	struct node* top;//��ָ��
};

//��ʼ��
void init(struct stack* st);

//�ж��Ƿ�Ϊ��
int isempty(struct stack* st);

//��ӡ����
void show(struct stack* st);

//ѹջ����ջ�д������ݣ�
void push(struct stack* st, int data);

//�����ڵ㣬�������½��ڵ����һ���ڵ�
struct node* creat_node(int data, struct node* p_next);
//��ջ�������ݴ�ջ����ȡ������
int pop(struct stack* st);

//�õ�ջ��Ԫ��
int get_top(struct stack* st);

//ջ���
void pop_all(struct stack* st);