/*
QQ1-����ϵͳ--�ײ�Ӳ����tcp/ip��--�ײ�Ӳ��--����ϵͳ--QQ2
�ֲ�ʽӦ��--ACE��
����ͼ����--openCV

�������ҵT�ͷ�չ���������ٺ�����չT
endl�建��
const char* p="hello";	
���ƿռ����namespace abc=a:b:c
�������ڵı�������һ���ڴ�
*/
#include<iostream>
typedef struct student
{
	char name[10];
	int age;
}STU;
struct s_student
{
	int m;
	void ss();
};
enum color
{
	RED,
	GREE
};
union MyUnion
{
	char i;
	int j;
};
int main()
{
	struct student s1;
	STU s2;
	s_student s3;
	//c++�ϸ����ͼ��
	color a = RED;
	MyUnion U;
	std::cin >> U;
}