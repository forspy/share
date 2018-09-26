#pragma once
struct node
{
	int ID;
	struct node* prv;//ָ��ǰһ���ڵ�
	struct node* next;//ָ���һ���ڵ�
};
//Ϊ�˷�ָֹ��ͷβ��ָ�뱻�޸ģ�����ṹ���ڣ�Сϰ��
struct dlist
{
	struct node* p_head;
	struct node* p_end;
};

//��ʼ��
void init(struct dlist*);
//�ж��������Ƿ��нڵ�
int isempty(struct dlist* list);

//���ؽڵ����
int getsize(struct dlist*);

//��ʾ������Ϣ
void show(struct dlist* list);
////��ȡͷ�ڵ�
//int get_head_data(struct dlist* list);

//β�巨
int insert_end(struct dlist* list,int data);

//ͷ�巨
int insert_head();

//βɾ��
int del_end();

//ͷɾ��
int del_head();

//�ı�ڵ�
int change_node();

//���ҽڵ�
int find_node();