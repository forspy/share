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
	static double m_sales;//销售总额
	static int m_id;//编号
public:
	Employee(string name="Nobody",string career="None"):m_name(name),m_career(career){ }//基类构造函数
	void Salary(double salary);
	double SetSales(double sales=0);
	void SetName();
	void SetID();
	void Show();//查看完整信息
	int ID();
	//虚函数---
	virtual void SetSalary() = 0;//纯虚函数
};
class Manager :public Employee//经理类
{
public:
	Manager(string name="Nobody",string career="经理"):Employee(name,career){ }//派生类构造函数
	//虚函数----
	virtual void SetSalary();//派生类虚函数实现
};

class Technician :public Employee//技术人员类
{
public:
	Technician(string name = "Nobody", string career = "技术人员"):Employee(name,career){ }//派生类构造函数
	//虚函数----
	virtual void SetSalary();//派生类虚函数实现,必须和抽象基类相同
};

class SalesManager :public Employee//销售经理类
{
public:
	SalesManager(string name = "Nobody", string career = "销售经理") :Employee(name, career) { }//派生类构造函数
	//虚函数----
	virtual void SetSalary();//派生类虚函数实现,必须和抽象基类相同
};

class SalesMan :public Employee//推销员类
{
public:
	SalesMan(string name = "Nobody", string career = "推销员") :Employee(name, career) { }//派生类构造函数
	//虚函数----
	virtual void SetSalary();//派生类虚函数实现,必须和抽象基类相同
};
//将基类指针保存成链表（方便插入和查询）
//
struct node
{
	Employee* p;//储存基类指针，指向派生类
	int id;//节点id记录该节点的id，基类静态ID保存已经有的ID的累加
	struct node* next;
};

//初始化
void init();
//插入信息（头插法插入一个基类指针）
void appendHead();
//显示所有信息
void showAllNode();
//查找ID，显示信息
void search();