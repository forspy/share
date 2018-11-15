#include<iostream>
#include"stack.h"
template<template<class	T>class Thing>//template<class	T>class��ģ������ Thing������
class Crab
{
private:
	Thing<int> s1;//1.ȷ����ģ������
	Thing<double> s2;
public:
	Crab() {};
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int& a, double& x) { return s1.pop(a) && s2.pop(x); }//���������н׶ξ���������������û���Զ���ȫ��
};

int main()
{
	using namespace std;
	Crab<Stack> nebula;//ȷ����������
	int ni;
	double nb;
	while (cin >> ni >> nb&&ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}
	while (nebula.pop(ni, nb))
		cout << ni << "," << nb << endl;
}