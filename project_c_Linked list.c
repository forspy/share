#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"link_list.h"
//��̬���������ӻ�ɾ��һ������ʱ����Ҫ�ƶ��������У�����ʱ����Ҫ����ԭ���У�����б�����ˣ�����������
struct link_node
{
	struct link_node* next;
};
typedef struct link_node* list_head;
struct rect
{
	int x;
	int y;
	int w;
	int h;
};
struct circle
{
	int x;
	int y;
	int r;
};
struct shape
{
	int type;
	int order;//���
	union
	{
		struct rect r;
		struct circle c;
	}u;
	struct link_node link;
};

struct shape* alloc_shape();
void free_shape(struct shape* s);
void list_insert_head(struct link_node** walk, struct link_node* node);//ͷ����ڵ�
void list_insert_tail(struct link_node** walk, struct link_node* node);//β������ڵ�
void list_remove(struct link_node** walk, struct link_node* node);//ɾ���ڵ�
int main()
{
	struct link_node* head=NULL;//����ͷ

	//ͷ�������棩����ڵ�
	struct shape* s = alloc_shape();
	s->order = 1;
	list_insert_head(&head, &s->link);//->�����ȼ���&�ߣ�Ҫ�ı�ʵ���ڴ��ֵ��Ҫ�����Ӧ�ĵ�ַ
	//ͷ�������棩��������ڵ�
	s = alloc_shape();
	s->order = 2;
	list_insert_head(&head, &s->link);
	//β�������棩����ڵ�
	s = alloc_shape();
	s->order = 3;
	list_insert_tail(&head, &s->link);
	


	//�������������е�Ԫ��
	struct link_node* pointer = head;
	while (pointer)//�нڵ�
	{
		//��������ڵ�
		//����ַ+offset=&������ַ->��Ա����������ַ=0ʱ��offset=&��NULL->��Ա��
		struct shape* elem = (struct shape*)((char*)pointer - (int)(&(((struct shape*)NULL)->link)));
		printf("elem->order=%d\n", elem->order);

		pointer = pointer->next;
	}
	printf("-----------------------\n");
	//ɾ��һ���ڵ�
	list_remove(&head, &s->link);

	//�������������е�Ԫ��
	struct link_node* pointer1 = head;
	while (pointer1)//�нڵ�
	{
		//��������ڵ�
		//����ַ+offset=&������ַ->��Ա����������ַ=0ʱ��offset=&��NULL->��Ա��
		struct shape* elem = (struct shape*)((char*)pointer1 - (int)(&(((struct shape*)NULL)->link)));
		printf("elem->order=%d\n", elem->order);

		pointer1 = pointer1->next;
	}
}

struct shape* alloc_shape()
{
	struct shape* s = malloc(sizeof(struct shape));
	memset(s, 0, sizeof(struct shape));
	return s;
}
void free_shape(struct shape* s)
{
	free(s);
}
void list_insert_head(struct link_node** walk, struct link_node* node)//ͷ����ڵ�
{
	//struct link_node** walk = header;//walk�൱��temp�м���������ڸı�����
	node->next = *walk;
	*walk = node;
}
void list_insert_tail(struct link_node** walk, struct link_node* node)//β������ڵ�
{
	while (*walk)
	{
		walk = &((*walk)->next);
	}
	*walk = node;
	node->next = NULL;
}
//�Ƴ�һ���ڵ�
void list_remove(struct link_node** walk, struct link_node* node)
{
	while (*walk)
	{
		if (*walk == node)
		{
			*walk = node->next;
			node->next = NULL;
			return;//����
		}
		walk = &((*walk)->next);
	}
}