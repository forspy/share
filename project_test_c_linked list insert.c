#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int ID;
	int age;
	char* name;
	struct student* next;//ָ����һ���ڵ�
};
//����һ������ͷ
struct student head;
//��ʼ��
void init();
//������Ϣ
void append(int ID, int age, char* name);
//��ʾ������Ϣ
void show();
//�ṩ���ҹ���
void search(int ID);
//��ָ��λ�ò���
void insert(int pos, int ID, int age, char* name);
//ͷɾ��
void del_node_head();
//βɾ��
void del_node_end();
//�ı�ֵ
void change(int ID, int value);
int main()
{
	init();
	append(1, 18, "joker");
	append(2, 19, "batman");
	append(3, 20, "riddle");
	append(4, 21, "Penguin");
	append(5, 22, "scarecrow");
	del_node_head();
	del_node_end();
	insert(4, 99, 99, "insert");//ע��head��1������pos=4�ǲ���3����
	change(4, 99);
	show();
	printf("������Ҫ���ҵ�ѧ��ID��\n");
	int num;
	scanf("%d", &num);
	search(num);
	free(head.next);//�ͷŶ����ڴ�
}
//��ʼ��
void init()
{
	head.ID = 0;
	head.age = 0;
	head.name = NULL;
	head.next = NULL;
}
//������Ϣ
void append(int ID, int age, char* name)
{
	//1.����ڵ�
	struct student* newnode = (struct student*)malloc(sizeof(struct student));
	//����ڴ治��������
	if (!newnode)
		return;
	//2.�Խڵ㸳ֵ
	newnode->ID = ID;
	newnode->age = age;
	newnode->name = name;
	newnode->next = NULL;//�ڵ�β����ֵNULL
						 //3.���ӣ�β�巨��
	struct student* p = &head;//���ô��ƶ���ָ��ָ��ͷ��
	while (p->next)
	{
		p = p->next;
	}
	p->next = newnode;
}
void insert(int pos, int ID, int age, char* name)
{
	//1.�ж�pos�Ƿ���ȷ
	struct student* p = &head;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
		if (p==NULL)
		{
			printf("pos������Χ\n");
			break;
		}
	}
	//1.����ڵ�
	struct student* newnode = (struct student*)malloc(sizeof(struct student));
	//����ڴ治��������
	if (!newnode)
		return;
	//2.�Խڵ㸳ֵ
	newnode->ID = ID;
	newnode->age = age;
	newnode->name = name;
	newnode->next = NULL;//�ڵ�β����ֵNULL
	
	newnode->next = p->next;
	p->next = newnode;
}
//
void del_node_head()//ͷɾ��
{
	struct student* pn = (&head)->next;
	if (pn)
	{
		(&head)->next = pn->next;
		free(pn);//�ͷ�ɾ���ڵ�
	}
	else
		printf("ֻ��һ��headͷ�ڵ�\n");
}
//βɾ��
void del_node_end()
{
	struct student* p = &head;
	if (p->next)
	{
		while (p->next->next)
		{
			p = p->next;
		}
		p->next = NULL;
		free(p->next);//ָ��β���ڵ�free���һ���ڵ����
	}
	else
		printf("ֻ��һ��ͷ�ڵ�\n");
}
//ָ��λ��ɾ���ڵ�

//�ı�ָ��ID����ֵ
void change(int ID, int value)
{
	struct student* p = &head;
	while (p->next)
	{
		p = p->next;
		if (p->ID == ID)
		{
			p->age = value;
			return;
		}
	}
	printf("û���ҵ�����Ϣ\n");
}
//��ʾ������Ϣ
void show()
{
	struct student* p = &head;
	while (p->next)
	{
		p = p->next;
		printf("ID=%d age=%d name=%s\n", p->ID, p->age, p->name);
	}
}
//�ṩ���ҹ���
void search(int ID)
{
	struct student* p = &head;
	while (p->next)
	{
		p = p->next;
		if (p->ID == ID)
		{
			printf("ID=%d age=%d name=%s\n", p->ID, p->age, p->name);
			return;
		}
	}
	printf("û���ҵ�����Ϣ\n");
}