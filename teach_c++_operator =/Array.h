#pragma once
#include<iostream>
using namespace std;
class my_Array//����һ��������
{
private:
	int m_size;//����64λ�ܹ��б�����Ϊ��typedef unsigned long size_t;�����ʾΪһ������
	int *m_array;
public:
	my_Array(int size=1);
	my_Array(const my_Array& arr);//��������
	~my_Array();
	int size() {return m_size;}
	int& at(int index);//��ֵ����&
	//���д�.�������sizeof�������أ�5���� ���Ա����(.)��ָ���Ա��ָ�� (.*)����Χ���� (::)���������ʽ (? :)����sizeof��
	//= () [] -> ->* �����ǳ�Ա����
	//<< >>��Ԫ����
	//��Ŀ�����Ա
	//˫Ŀ������Ԫ
	//operator=����
	my_Array& operator=(const my_Array& arr);//��ֵ����
	friend ostream& operator<<(ostream& os, const my_Array& arr);
};

