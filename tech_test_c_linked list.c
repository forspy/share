#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node//�ڵ�
{
	int data;
	struct node* next;//ָ����һ���ڵ�
};

typedef struct node node;
typedef struct node* pnode;

struct node head;//����ͷ
		  //pnode p_head = &head;//����һ��ָ��ͷ��ָ��
struct node* p_head = &head;
void append(int DATA);
void show();
int main()
{
	append(10);
	append(20);
	append(30);
	show();
}

void init()//��ʼ��
{
	p_head->data = 0;
	p_head->next = NULL;
}

void append(int DATA)//β�巨
{
	//1.����ڵ�
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	//����ڴ治��������
	if (!newnode)
	{
		printf("�����ڴ�ʧ��\n");
		return;
	}
	//2.��ֵ
	newnode->data = DATA;
	newnode->next = NULL;//ע���²���Ľڵ�
	//3.����
	//p_head->next = newnode;
	//�ҵ����һ���ڵ�
	struct node* p = p_head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = newnode;
}
void show()
{
	struct node* p = p_head;
	while (p->next)
	{
		p = p->next;
		printf("%d\n", p->data);
	}
}