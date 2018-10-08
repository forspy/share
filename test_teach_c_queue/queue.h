#pragma once
struct node
{
	int data;
	struct node* next;
};

//Ϊ�˴��η��㣬��װ����ȫ
struct queue
{
	struct node* front;//���е�ͷ
	struct node* rear;//���е�β
};
//��ʼ��
void init(struct queue* qu);

//�����
void push(struct queue* qu, int data);
//������
int pop(struct queue* qu);
//��ʾ��������
void show(struct queue* qu);
//��ȡ����Ԫ��
int get_front(struct queue* qu);
//�õ����д�С
int get_size(struct queue* qu);
//�ж��Ƿ�Ϊ��
int isempty(struct queue* qu);