#include"Integer.h"
#include<iostream>
using namespace std;
int main()
{
	Integer i1(10), i2(20);
	//��ָͨ�룺ͨ��ȡ��ַ����-----
	int* p1 = &i1.m_i;
	int* p2 = &i2.m_i;
	cout << p1 << endl;
	cout << p2 << endl;
	//----------------
	//��Աָ�� ��ʾ���Ǹó�Աָ���������������ƫ��ֵ
	//�ӽ���Զ�����ҵ�����������
	int Integer::* p = &Integer::m_i; //(int Integer::)��Integer�����int���͵Ķ���2.Ҫ��������һ�£����ʵ�����ʵ��ƫ��ֵ
	//*p��ʵ������ǳ�Ա
	cout << "��Pֱ�����" << endl;
	//cout << p << endl;//
	//ͨ��.*����Աָ��ָ��ĳ�Ա��ֵ�����i1��һ������ָ����Ϊ->*��
	i1.*p = 50;
	A a;
	int A::* pa = NULL;
	//Ŀ�������paָ���ֵ������ַ
	cout << pa << endl;//ֱ����������ʾ0��Ϊʲô��
	cout << "------" << endl;
	cout << *(int*)&pa << endl;//(int*)&pa�ǰ�int A::���͵�ָ��pa�ĵ�ַǿ��ת����(int*)���ͣ�*(int*)&paȻ������õõ�pa��ֵ����NULL����Ե�ַ��ƫ������
	pa = &A::m_a;
	cout << *(int*)&pa << endl;
	pa = &A::m_b;
	cout << *(int*)&pa << endl;
	//���Ͻ����ʾ��ָ�����Զ���ƫ�ƣ����Խг�Աָ��
	//ǿת����Ա�����Ӱ�죬�൱�ڱ�������һ���������ͽ��ͳ���һ����������
	//volatile
}