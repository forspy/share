#include"class_operator1.h"

Complex operator+(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.m_real = c1.m_real + c2.m_real;
	temp.m_vir = c1.m_vir + c2.m_vir;
	return temp;
}

Complex Complex::operator-(const Complex& c2)
{
	Complex temp;
	temp.m_real = this->m_real - c2.m_real;
	temp.m_vir = this->m_vir - c2.m_vir;
	return temp;
}
Complex& Complex::operator++()
{
	this->m_real++;
	this->m_vir++;
	//++*this;//Ҳ���Ե���ǰ++ʵ��ǰ������
	return *this;
}
//��++����
Complex Complex::operator++(int)//��Ԫ
{
	Complex temp = *this;
	this->m_real++;
	this->m_vir++;
	return temp;
}
ostream& operator<<(ostream& os, const Complex&c)
{
	os << c.m_real << "+" << c.m_vir << "i";
	return os;
}

istream & operator >> (istream & is, Complex & c)
{
	is >> c.m_real >> c.m_vir;
	return is;
	// TODO: �ڴ˴����� return ���
}
