#pragma once
//虚函数原理：虚函数表
#include<iostream>
using namespace std;
class N//普通成员函数
{
public:
	void foo() { cout << "N:foo" << endl; }
	void bar() { cout << "N:bar" << endl; }
	int m_a;
	int m_b;
};

class Base//普通基类
{
public:
	virtual void foo() { cout << "Baes:foo" << endl; }//virtual void foo(*this)
	virtual void bar() { cout << "Base:bar" << endl; }
	int m_a;
	int m_b;
};

class Child:public Base
{
public:
	virtual void foo() { cout << "Child:foo" << endl; }
	virtual void bar() { cout << "Child:bar" << endl; }
	int m_a;
	int m_b;
};