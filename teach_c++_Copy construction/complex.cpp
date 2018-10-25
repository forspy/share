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
//1.�������죬���ȥ��&�൱���ڶ����Ƶ�that�����ֻ´�����γ����޿���
//2.û���Զ��忽�����캯�������������ṩĬ�Ͽ������캯������ʹ��д���������캯����
{
	
	this->m_real = that.m_real;
	this->m_vir = that.m_vir;
}