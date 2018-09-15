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
int main()
{
	init();
	append(1, 18, "joker");
	append(2, 19, "batman");
	append(3, 20, "riddle");
	append(4, 21, "Penguin");
	append(5, 22, "scarecrow");
	//show();
	printf("������Ҫ���ҵ�ѧ��ID��\n");
	int num;
	scanf("%d", &num);
	search(num);
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
void append(int ID,int age,char* name)
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
}