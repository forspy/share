#pragma once
#include<iostream>
using namespace std;
class Mystring
{
private:
	char* m_str;//char*指针
	int m_len;//长度
public:
	Mystring();
	Mystring(char* str );
	Mystring(const Mystring& mystr);
	//= []必须为成员函数
	Mystring& operator=(const Mystring& mystr);
	char operator[](int n);
	int length();
	//双目运算符(建议友元)
	friend Mystring operator+(const Mystring& mystr1, const Mystring mystr2);
	friend Mystring& operator+=(Mystring& mystr1,const Mystring& mystr2);
	//<< >>必须为友元
	friend ostream& operator<<(ostream& os, const Mystring& mystr);//注意重载<<要使用using namespace std;
	friend istream& operator >> (istream& is, Mystring& mystr);//要修改的对象不能const
	~Mystring();
};

