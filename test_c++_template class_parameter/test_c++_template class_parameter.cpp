#include<iostream>
#include"stack.h"
template<template<class	T>class Thing>//template<class	T>class是模板类型 Thing是类名
class Crab
{
private:
	Thing<int> s1;//1.确定了模板类型
	Thing<double> s2;
public:
	Crab() {};
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int& a, double& x) { return s1.pop(a) && s2.pop(x); }//由于是运行阶段决定类型名，所以没有自动补全了
};

int main()
{
	using namespace std;
	Crab<Stack> nebula;//确定了类型名
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