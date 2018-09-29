#include"double linked list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init(struct dlist* list)//p_head��p_endΪȫ�ֱ���
{
	list->p_head = NULL;
	list->p_end = NULL;
}

//���û�нڵ�
int isempty(struct dlist* list)
{
	return !(list->p_head) && !(list->p_end);//����û�нڵ㷵��1���нڵ㷵��0
}
//��������Ľڵ����
int getsize(struct dlist* list)
{
	if (isempty(list))//�������Ϊ�գ���ôҲ������prv��next������Ҫ���ж������Ƿ�ΪNULL
	{
		printf("����Ϊ��\n");
		return 0;
	}
	int size = 0;
	struct node* p = list->p_end;

	//����Ӻ���ǰ�ң�Ҳ���Դ�ǰ�����ң�����p=list->p_head
	while (p)
	{
		p = p->prv;
		size++;
	}
	printf("˫������ڵ����Ϊ%d\n", size);
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
	struct node* p = list->p_head;//ʹ��һ����ʱ����pȥ���������ı�p_head��ָ��p_head����ָͷ
	//��ͷ�����±���
	while (p)
	{
		printf("%d<->", p->ID);
		p = p->next;
	}
}
//�½ڵ���malloc�����ڴ棬���Ըýڵ��ǰ���������
struct node* creat_data(int data, struct node* p_next, struct node* p_prv)//p_next��p_next��ʾ�����¿��ڵ����һ���ڵ�ĵ�ַ����һ���ڵ�ĵ�ַ
{
	struct node* p = (struct node*)malloc(sizeof(struct node));//����һ���ڵ��ڴ�
	if (!p)
	{
		printf("����ڵ�ʧ��\n");
		return NULL;
	}
	p->ID = data;
	p->next = p_next;
	p->prv = p_prv;
	return p;
}
//β�巨
void insert_end(struct dlist* list, int data)
{
	//if (isempty(list))
	//{
	//	printf("����Ϊ��\n");
	//	return 0;
	//}
	
	//���ƶ�p_end������
	list->p_end = creat_data(data, NULL, list->p_end);
	//1.�½ڵ���malloc�����ڴ棬���Ըýڵ��ǰ���������
	//2.��p_endָ�������½ڵ㣬ע�������p_end��һ��ȫ�ֱ������ں����ڸı�p_end��ָ�����ⲿҲ��ı�p_end��ָ��
	if (list->p_end->prv)//���p_endָ���½ڵ��Ժ��½ڵ��ǰ�滹�нڵ㣬Ҳ����˵��ֹһ���ڵ�>=2
	{
		list->p_end->prv->next = list->p_end;
		//3.��ǰһ���ڵ������½ڵ㣬����������˫����������ƣ��õ���ǰһ���ڵ��next����list->p_end->prv->next�����ӵ���ǰ��list->p_end
	}
	else//ֻ��һ���ڵ�
	{
		list->p_head = list->p_end;//ֻ��һ���ڵ�Ļ���ͷ��Ҳָ������ڵ�
	}
	//������
	/*
	//�������ƶ�p_end
	list->p_end->next = creat_data(data, NULL, list->p_end);
	list->p_end = list->p_end->next;
	*/

}
//ɾ��һ���ڵ㣬������һ���ڵ��ַ,������ʽ�ط�����һ���ڵ�ĵ�ַ
struct node* delete_node(struct node* node, struct node** p_prv)//nodeΪҪɾ���Ľڵ��ַ��p_prvΪǰһ���ڵ㣬��Ϊֻ�ܷ���һ��ֵ������ͨ����������ָ�뷵��
{
	struct node* temp = node->next;//����ʱtempָ�뱣����һ���ڵ�ĵ�ַ������Ҫ����
	//ʹ��Ҫɾ���ڵ�� ��һ���ڵ��prvָ�� ָ��Ҫɾ���ڵ��ǰһ���ڵ�

	//���⣿��ΪɶҪ��Ҫɾ���ڵ�� ��һ���ڵ��prvָ��ĵ�ַ����������node->next->prv���������
	
	if (p_prv)//������ǰһ���ڵ�
	{
		*p_prv = node->prv;//������һ��
	}
	free(node);
	return temp;
}

//ָ��λ��ɾ��
void del_pos(struct dlist* list, int pos)
{
	struct node* p = list->p_head;
	//prvǰ�ڵ� next��ڵ�
	//ָ��λ��ɾ�����Ż�����ʹ�û��������汾
	for (int i = 0; i < pos-1; i++)
	{
		p = p->next;
		//���Ż������Ż���
		if (p== NULL)
		{
			printf("Ҫɾ����posλ�ó�������ڵ���\n");
			return;
		}
	}
	struct node* p_prv = NULL;//�ȶ���һ��ǰ�ڵ�
	struct node* p_next = delete_node(p, &p_prv);//���غ�һ���ڵ�
												 //ǰ�ڵ��next���Ӻ�ڵ�
	if (p_prv)//���ǰ�ڵ㲻Ϊ��
	{
		p_prv->next = p_next;
	}
	else//���û��ǰ�ڵ���p_headָ���ڵ�
	{
		list->p_head = p_next;
	}
	//��ڵ��prv����ǰ�ڵ�
	if (p_next)
	{
		p_next->prv = p_prv;
	}
	else//���û�к�ڵ���p_endָ��ǰ�ڵ�
	{
		list->p_end = p_prv;
	}
}

//ָ��λ��ɾ��version 1.1,��ʹ�ú�����װ����ǰ��ڵ�ķ���������������
void del_pos_v1(struct dlist* list, int pos)
{
	struct node* p = list->p_head;
	//prvǰ�ڵ� next��ڵ�
	//ָ��λ��ɾ�����Ż�����ʹ�û��������汾
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
		//���Ż������Ż���
		if (p == NULL)
		{
			printf("Ҫɾ����posλ�ó�������ڵ���\n");
			return;
		}
	}
	struct node* p_prv = p->prv;//�ҵ�p��ǰ�ڵ�
	struct node* p_next = p->next;//�ҵ�p�ĺ�ڵ�
	if (p_prv)//���ǰ�ڵ㲻Ϊ��
	{
		p_prv->next = p_next;
	}
	else//���û��ǰ�ڵ���p_headָ���ڵ�
	{
		list->p_head = p_next;
	}
	//��ڵ��prv����ǰ�ڵ�
	if (p_next)
	{
		p_next->prv = p_prv;
	}
	else//���û�к�ڵ���p_endָ��ǰ�ڵ�
	{
		list->p_end = p_prv;
	}

}
//���ҽڵ�
int find_node(struct dlist* list, int data)
{
	int pos = 1;
	struct node* p = list->p_head;
	while (p)
	{
		if (p->ID == data)
		{
			return pos;
		}
		p = p->next;
		pos++;
	}
	return 0;
}
//�ı�ڵ�
void change_node(struct dlist* list, int data, int new_data)
{
	struct node* p = list->p_head;
	while (p)
	{
		if (p->ID == data)
		{
			p->ID = new_data;
		}
		p = p->next;
	}
}
//ͷɾ��
void del_head(struct dlist* list)
{
	if (isempty(list))
	{
		printf("û�нڵ�\n");
		return ;
	}
	struct node* p_prv = NULL;//�ȶ���һ��ǰ�ڵ�
	struct node* p_next = delete_node(list->p_head, &p_prv);//���غ�һ���ڵ�
	list->p_head = p_next;//ͷ��ָ��������һ���ڵ�
	if (list->p_head)//������2���ڵ����ϣ�ɾ��һ������һ������
	{
		list->p_head->prv = NULL;
	}
	else//���е�һ���ڵ�Ҳ��ɾ����
	{
		//list->p_end = NULL;
		list->p_end = list->p_head;//���¶���
	}
}
//βɾ��
void del_end(struct dlist* list)
{
	if (isempty(list))
	{
		printf("û�нڵ�\n");
		return;
	}
	struct node* p_prv = NULL;//�ȶ���һ��ǰ�ڵ�
	struct node* p_next = delete_node(list->p_end, &p_prv);//���غ�һ���ڵ�
	list->p_end = p_prv;//β��ָ��ָ��ǰһ���ڵ�
	if (list->p_end)//������2���ڵ����ϣ�ɾ��һ������һ������
	{
		list->p_end->next = NULL;
	}
	else // ���е�һ���ڵ�Ҳ��ɾ����
	{
		list->p_head = NULL;
	}
}

//ͷ�巨
void insert_head(struct dlist* list, int data)
{
	list->p_head=creat_data(data, list->p_head, NULL);

	if (list->p_head->next)
	{
		list->p_head->next->prv = list->p_head;//��һ���ڵ��prv����p_head
	}
	else//��������ֻ��һ���ڵ㣬�ͽ�p_endָ��p_head��ͬһ���ڵ�
	{
		list->p_end = list->p_head;
	}
}