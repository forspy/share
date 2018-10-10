#pragma once
struct node
{
	int ID;
	struct node* prv;//ָ��ǰһ���ڵ�
	struct node* next;//ָ���һ���ڵ�
};
//Ϊ�˷�ָֹ��ͷβ��ָ�뱻��������޸ģ�����ṹ���ڣ���ֹ�ּ��������޸ģ�����ͷβָ����ָ
//����ʹ��p_head��p_endֻ��ͨ���ṹ��ȥ����
struct dlist
{
	struct node* p_head;//ָ��������ͷ��
	struct node* p_end;//ָ��������β��
};

//��ʼ��
void init(struct dlist*);
//�ж��������Ƿ��нڵ�
int isempty(struct dlist* list);

//���ؽڵ����
int getsize(struct dlist*);

//��ʾ������Ϣ
void show(struct dlist* list);

//β�巨
void insert_end(struct dlist* list, int data);

//ɾ��һ���ڵ㣬������һ���ڵ��ַ,������ʽ�ط�����һ���ڵ�ĵ�ַ
struct node* delete_node(struct node* node, struct node** p_prv);

//ָ��λ��ɾ��
void del_pos(struct dlist* list, int pos);
//ָ��λ��ɾ��version 1.1
void del_pos_v1(struct dlist* list, int pos);


//���ҽڵ�
int find_node(struct dlist* list, int data);

//�ı�ڵ�
void change_node(struct dlist* list, int data, int new_data);

//ͷɾ��
void del_head(struct dlist* list);

//ͷ�巨
void insert_head(struct dlist* list, int data);


//βɾ��
void del_end(struct dlist* list);