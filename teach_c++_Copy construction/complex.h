#pragma once
#include<iostream>
using namespace std;
class Complex
{
private:
	double m_real;
	double m_vir;
	//c++自动提供下面成员函数：
	/*
	if no ...
	提供默认构造函数、拷贝构造、析构函数、赋值运算符、地址运算符
	*/
public:
	Complex();
	Complex(double real);//单参类型转换构造函数 用explicit可以防止隐式使用 比如complex a=1.2;不行 
	Complex(const Complex& that);//单参同类型构造
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
		cout << "默认构造" << endl;
	}
	explicit ninjia(int age) :m_age(NULL)
	{
		if (age >= 0)
		{
			m_age = new int(age);
		}
		cout << "单参构造" << endl;
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
		cout << "析构" << endl;
	}
	void show()
	{
		cout << *m_age << "岁" << endl;
	}
};
