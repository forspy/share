#pragma once
#include<iostream>
using namespace std;
//���ص����ȼ�����ı�
class Complex
{
private:
	double m_real;
	double m_vir;
public:
	Complex(double real=0,double vir=0):m_real(real),m_vir(vir){}
	void print() { cout << m_real << "+" << m_vir << "i" << endl; }
	Complex operator-(const Complex& c2);
	Complex& operator++();//ǰ++
	Complex operator++(int);//��++
	//��Ԫ
	friend Complex operator+(const Complex& c1,const Complex& c2);
	friend ostream& operator<<(ostream& os,const Complex&c);
};
//���д�.�������sizeof�������أ�5����. ��.* ��:: ��? : ��sizeof��typeid
//= () [] -> ->* �����ǳ�Ա����
//<< >>��Ԫ����
//��Ŀ�����Ա
//˫Ŀ������Ԫ