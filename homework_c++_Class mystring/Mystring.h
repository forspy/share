#pragma once
#include<iostream>
using namespace std;
class Mystring
{
private:
	char* m_str;//char*ָ��
	int m_len;//����
public:
	Mystring();
	Mystring(char* str );
	Mystring(const Mystring& mystr);
	//˫Ŀ�����(������Ԫ)
	friend Mystring operator+(const Mystring& mystr1, const Mystring mystr2);
	friend Mystring& operator+=(Mystring& mystr1,const Mystring& mystr2);
	//<< >>����Ϊ��Ԫ
	friend ostream& operator<<(ostream& os, const Mystring& mystr);//ע������<<Ҫʹ��using namespace std;
	~Mystring();
};

