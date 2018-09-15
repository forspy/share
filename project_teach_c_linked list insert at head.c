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
	append(1, 123, "joker");
	append(2, 110, "batman");
	show();
	printf("ͷ�巨����һ������\n");
	append(3, 666, "Penguin");
	show();
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
	newnode->next = p->next;//�Ȱ�head��nextָ��ֵ��newnode��next
	p->next = newnode;//�ٰ�newnode��ֵ��head��next
}
//��ʾ������Ϣ
void show()
{
	struct student* p = &head;
	while (p->next)
	{
		p = p->next;
		printf("%d \n", p->age);
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