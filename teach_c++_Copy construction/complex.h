#pragma once
#include<iostream>
using namespace std;
class Complex
{
private:
	double m_real;
	double m_vir;
public:
	Complex();
	Complex(double real);//��������ת�����캯�� ��explicit���Է�ֹ��ʽʹ�� ����complex a=1.2;���� 
	Complex(const Complex& that);//����ͬ���͹���
	~Complex();
	void print()const;
};

class ninjia
{
private:
	int* m_age;
public:
	ninjia()
	{
		cout << "Ĭ�Ϲ���" << endl;
	}
	explicit ninjia(int age) :m_age(NULL)
	{
		if (age >= 0)
		{
			m_age = new int(age);
		}
		cout << "���ι���" << endl;
	}

	ninjia(const ninjia& that)
	{
		this->m_age = new int;
		*m_age = *(that.m_age);
		//m_age = that.m_age;
	}
	~ninjia()
	{
		if (m_age)
		{
			delete m_age;
			//m_age = NULL;
		}
		cout << "����" << endl;
	}
	void show()
	{
		cout << *m_age << "��" << endl;
	}
};
