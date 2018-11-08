#pragma once
#include<string>
#include<iostream>
using namespace std;
//基本思路是利用链表储存一系列基类指针，在找到对应ID的节点后使用基类指针访问抽象类对象的方法

class Employee//抽象基类
{
private:
	string m_name;//姓名
	string m_career;//职业类型
	double m_salary;//薪水
public:
	
	Employee(string name="Nobody",string career="None"):m_name(name),m_career(career){ }//基类构造函数
	void Name();
	void Salary(double salary);
	void Show();
	//虚函数---
	virtual void SetSalary() = 0;//纯虚函数
};
class Manager :public Employee//经理类
{
public:
	Manager(string name="Nobody",string career="Employee"):Employee(name,career){ }//派生类构造函数
	//虚函数----
	virtual void SetSalary();//派生类虚函数实现
};

class Technician :public Employee//技术人员类
{
public:
	Technician(string name = "Nobody", string career = "Technician"):Employee(name,career){ }//派生类构造函数
	//虚函数----
	virtual void SetSalary();//派生类虚函数实现,必须和抽象基类相同
};

class SalesManager :public Employee//销售经理类
{
public:
	SalesManager(string name = "Nobody", string career = "SalesManager") :Employee(name, career) { }//派生类构造函数
	//虚函数----
	virtual void SetSalary();//派生类虚函数实现,必须和抽象基类相同
};

class SalesMan :public Employee//推销员类
{
public:
	SalesMan(string name = "Nobody", string career = "SalesManager") :Employee(name, career) { }//派生类构造函数
	//虚函数----
	virtual void SetSalary();//派生类虚函数实现,必须和抽象基类相同
};
//struct node
//{
//	Employee* p;//储存基类指针，指向派生类
//	int ID;
//	struct node* next;
//};
