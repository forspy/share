#pragma once
#include<string>
class Integer
{
public:
	int m_i;
	Integer(int i):m_i(i){}
	~Integer();
};

//测试成员指针
class A
{
public:
	int m_a;
	std::string test;//占28字节
	int m_b;
	A(int a=10,int b=20):m_a(a),m_b(b){}
};
//防止隐式转换
class B
{
private:
	int m_a;
public:
	explicit B(int a=0):m_a(a){}//加explicit可以防止隐式构造
	int show() { return m_a; }
};