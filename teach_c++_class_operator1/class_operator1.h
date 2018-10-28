#pragma once
#include<iostream>
using namespace std;
//重载的优先级不会改变
class Complex
{
private:
	double m_real;
	double m_vir;
public:
	Complex(double real=0,double vir=0):m_real(real),m_vir(vir){}
	void print() { cout << m_real << "+" << m_vir << "i" << endl; }
	Complex operator-(const Complex& c2);
	Complex& operator++();//前++
	Complex operator++(int);//后++
	//友元
	friend Complex operator+(const Complex& c1,const Complex& c2);
	friend ostream& operator<<(ostream& os,const Complex&c);
};
//所有带.运算符和sizeof不能重载（5个） 类成员访问(.)，指向成员的指针 (.*)，范围解析 (::)，条件表达式 (? :)，和sizeof。
//= () [] -> ->* 必须是成员函数
//<< >>友元重载
//单目建议成员
//双目建议友元
