#pragma once
#include<iostream>
using namespace std;
class my_Array//定义一个数组类
{
private:
	int m_size;//而在64位架构中被定义为：typedef unsigned long size_t;这里表示为一共几个
	int *m_array;
public:
	my_Array(int size=1);
	my_Array(const my_Array& arr);//拷贝构造
	~my_Array();
	int size() {return m_size;}
	int& at(int index);//左值返回&
	//所有带.运算符和sizeof不能重载（5个） 类成员访问(.)，指向成员的指针 (.*)，范围解析 (::)，条件表达式 (? :)，和sizeof。
	//= () [] -> ->* 必须是成员函数
	//<< >>友元重载
	//单目建议成员
	//双目建议友元
	//operator=重载
	my_Array& operator=(const my_Array& arr);//左值引用
	friend ostream& operator<<(ostream& os, const my_Array& arr);//注意重载<<要使用using namespace std;
};

