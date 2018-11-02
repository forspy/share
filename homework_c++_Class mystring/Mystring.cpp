#define _CRT_SECURE_NO_WARNINGS
#include "Mystring.h"
#include<cstring>

Mystring::Mystring()
{
	m_len = 0;
	m_str = new char[m_len + 1];
	m_str[0] = '\0';
}
Mystring::Mystring(char* str)
{
	m_len = strlen(str);
	m_str = new char[m_len + 1];
	strcpy(m_str, str);
}
#if 0
Mystring::Mystring(char* str)//Ҳ����дһ��Ĭ�ϵ�Mystring()��Ȼ���else�����д��ȥ
{
	if (str)
		m_len = strlen(str);
	else
		m_len = 0;
	m_str = new char[m_len + 1];//�����ڴ�
	if (str)
		strcpy(m_str, str);//�����ַ�
	else
		m_str[0] = '\0';
}
#endif
Mystring::Mystring(const Mystring & mystr)
{
	m_len = mystr.m_len;
	m_str = new char[m_len + 1];
	strcpy(m_str, mystr.m_str);
}

Mystring & Mystring::operator=(const Mystring & mystr)
{
	//1.���ж��Ը�ֵ
	if (this == &mystr)
		return *this;
	//2.delete[]���ڴ�
	delete[] m_str;
	//3.�������ڴ�
	m_len = mystr.m_len;
	m_str = new char[m_len + 1];
	//4.����
	strcpy(m_str, mystr.m_str);
	return *this;
}

char Mystring::operator[](int n)
{
	char temp;
	temp = this->m_str[n];
	return temp;
}

int Mystring::length()
{
	return m_len;
}

Mystring::~Mystring()
{
	if (m_str)
	{
		delete[] m_str;
		m_str = NULL;
	}
}

Mystring operator+(const Mystring & mystr1, const Mystring mystr2)
{
	Mystring temp;
	temp.m_len = mystr1.m_len + mystr2.m_len;
	temp.m_str = new char[temp.m_len + 1];
	strcpy(temp.m_str, mystr1.m_str);
	strcat(temp.m_str, mystr2.m_str);
	return temp;
}

Mystring & operator+=(Mystring & mystr1, const Mystring & mystr2)
{
	mystr1 = mystr1 + mystr2;//��������+������=
	return mystr1;
	//����
}

ostream & operator<<(ostream & os, const Mystring & mystr)
{
	os << mystr.m_str;
	return os;
}

istream & operator >> (istream & is, Mystring& mystr)
{
	const int SIZE = 50;
	char temp[SIZE];
	is.get(temp, SIZE);
	mystr = temp; //��һ�����ô��ι��캯��
	while (is&&is.get() != '\n')//���50�����������������Ļ����Լ�'\n'
		continue;
	return is;
}

