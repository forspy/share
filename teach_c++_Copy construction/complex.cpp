#include"complex.h"

Complex::Complex()
{
	m_real = 0;
	m_vir = 0;
}

Complex::Complex(double real)
{
	m_real = real;
	m_vir = 0;
}

void Complex::print()const
{
	cout << m_real << "+" << m_vir << "i" << endl;
}
Complex::~Complex()
{
	cout << "done!" << endl;
}

Complex::Complex(const Complex& that)
//1.拷贝构造，如果去掉&相当于在对象复制到that过程又会拷贝，形成无限拷贝
//2.没有自定义拷贝构造函数，编译器会提供默认拷贝构造函数（即使你写了其他构造函数）
{
	
	this->m_real = that.m_real;
	this->m_vir = that.m_vir;
}