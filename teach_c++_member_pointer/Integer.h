#pragma once
#include<string>
class Integer
{
public:
	int m_i;
	Integer(int i):m_i(i){}
	~Integer();
};

//���Գ�Աָ��
class A
{
public:
	int m_a;
	std::string test;//ռ28�ֽ�
	int m_b;
	A(int a=10,int b=20):m_a(a),m_b(b){}
};
//��ֹ��ʽת��
class B
{
private:
	int m_a;
public:
	explicit B(int a=0):m_a(a){}//��explicit���Է�ֹ��ʽ����
	int show() { return m_a; }
};