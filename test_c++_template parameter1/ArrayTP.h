#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;
template<class T,int n>//�������Ͳ�����ģ���˽�һ��
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP() { };
	explicit ArrayTP(const T& v);
	virtual T& operator[](int i);
	virtual T operator[](int i)const;
};

template<class T, int n>
inline ArrayTP<T, n>::ArrayTP(const T & v)//����Ա���鶼��ֵΪV
{
	for (int i = 0; i < n; i++)
		ar[i] = v;
}

template<class T, int n>
inline T & ArrayTP<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		cerr << "error in array limits" << i << "is out of ranger" << endl;
		exit(EXIT_FAILURE);
	}
	return ar[i];
}

template<class T, int n>
inline T ArrayTP<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
	{
		cerr << "error in array limits" << i << "is out of ranger" << endl;
		exit(EXIT_FAILURE);
	}
	return ar[i];
}
