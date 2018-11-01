#pragma once
class Integer
{
public:
	int m_i;
	Integer(int i):m_i(i){}
	~Integer();
};

//²âÊÔ³ÉÔ±Ö¸Õë
class A
{
public:
	int m_a;
	int m_b;
	A(int a=10,int b=20):m_a(a),m_b(b){}
};