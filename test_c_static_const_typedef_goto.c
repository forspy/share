#include<stdio.h>
//��Ҫ���ô���������
static int ab;//static����ȫ�ֱ���ֻ�������.c�ļ���ʹ�ã����ٴ����ά���ɱ�
void change(const int* p);
struct student
{
	char name[20];
	int age;
};
int main()
{
	const int a = 10;//const ���εı������ܱ��޸�
	int xm;
	change(&xm);
	int* const ptr = &xm;
	//ptr = &xh;��ʾ�����޸����ָ���ָ��
	static int abc;//��abc��Ϊȫ�ֱ�������������ֻ�ں�����
	typedef unsigned int u_int;//typedef����һ���µ�����
	typedef struct student student;
	student xq;
	typedef struct student *student_ptr;//����һ��ָ�����͵�struct student*������student_ptr
	student_ptr xh = &xq;
	//FILE* û�м�struct����typedef�����ã�����
	//goto����ָ��ָ�룬����������������ѭ�����򿪶���ļ������д���
	int j ;
again: j = 1;
	printf("%d\n", j);
	goto again;//ʹ���Ժ��ô��������

}

void change(const int* p)
{
	//*p = 3;const���ε�ָ���ʾ��ָ�벻���޸���ָ�����ֵ�����ǿ����޸�p��ָ��
}