#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//strcpy��ͷ�ļ�
#include<stdlib.h>//malloc free ��ͷ�ļ�
struct student//����Ϊȫ�ֱ����Ľṹ�巽�����������ʹ�ã�ȫ�ֱ�������ھ�̬�洢��
{
	char name[20];
	int age;
};
void print_student1(struct student a);
void print_student2(struct student* b);
int main()
{
	//int j=1;
	//int j=2;//�ض���
	
	
	
	//�ٸ�����
	char kk[20];//kk��һ����ַ����������ֱ��kk="hello"
	char* p;
	p = "hello";
	printf("%s\n", p);
	strcpy(kk, "hello");
	printf("%s\n", kk);
	/////
	struct student xiaoming;
	strcpy(xiaoming.name ,"xiaoming");
	xiaoming.age = 18;
	printf("%s\n", xiaoming.name);

	struct student* ptr = (struct student*)malloc(sizeof(struct student));
	memset(ptr, 0, sizeof(struct student));//����д����������̬������ʼ��Ϊ0�����������Ļ�Ҫ*����Ԫ�صĸ���
	strcpy(ptr->name, "xiaowang");
	ptr->age = 20;
	printf("%s\n%d\n", (ptr->name)+1, ptr->age);//����ptr->name��һ��ָ��name�����ָ�룬��Ϊname�����Ǹ����飬��ptr->age��һ������
	free(ptr);

	//����һ����̬����
	struct student* pp= (struct student*)malloc(10*sizeof(struct student));
	int i;
	for (i = 0; i < 10; i++)
		(pp + i)->age = i;
	//���Բ���
    printf("i��ֵ%d\n", i);//����뱣��i��ֵ����Ҫ�������壨ѭ�������ȶ���i��Ȼ�����治�ض���ֱ�Ӹ�ֵ��
	//������뱣��i��ֵ
	/*
	1.�����ض���
	for (int i = 0; i < 10; i++)
	(pp + i)->age = i;
	2.���渳ֵi=0������Ȼ�ض���int i

	�ܽ᣺ֻҪ�����ض�����int i�������i���Ǹ���ʱ��������forѭ��������ᱻ�ͷ�
	*/
	//
	while ( i < 3)
		i++;
	
	//���Բ���
	//���ۣ�for/whileѭ���ڵ�ֻҪ���¶���ı�������i��j�Ȼᱻ�ͷŵ�����ʹ���ⲿ�ı����ᱻ����
	//�������ӣ���ѭ����������i����ѭ���������Ĳ�����������ʼ������ֵ�ȣ�����ı�i��ֵ��
	//ѭ�����ڲ�����ı���j����ѭ������ʱ���ͷ��ˣ������ں��滹���Զ���int j = 2�������ᱨ��
	for (int i = 0; i < 10; i++)
		printf("%d\n", (pp + i)->age);
	free(pp);
	print_student1(xiaoming);
	print_student2(&xiaoming);//ע���ǵ�ַ����
}
void print_student1(struct student a)//�����ǰ�xiaoming�������ṹ���ٿ���һ��
{
	printf("%s\n%d\n", a.name, a.age);
}

void print_student2(struct student* b)//��������һ���ṹ��ָ��ָ���xiaoming�������ṹ�壬��ʡ�˴���ռ�
{
	printf("%s\n%d\n", b->name, b->age);
}