#pragma once
#include<string>
#include<iostream>
using namespace std;
class Accout
{
private:
	string m_name;//账户名
	int m_no;//账号
	int m_pwd;//
	double m_balance;
	
public:
	static double m_rate;//1.声明利率，2.静态成员,静态成员不计入sizeof类3.普通成员是在构造的时候定义的
	Accout(string name="nobody",int no=0,int pwd=0,double balance=0):m_name(name),m_no(no),m_pwd(pwd),m_balance(balance){}
	void save(double money) { m_balance += money; }
	void draw(double money);
	void profit();//加利息
	void show();
	static void adjust(double value=0.01);
	~Accout();
};
//单例模式(用处：线程池、内存池化操作)
//饿汉模式（程序启动就创建）
//一个程序有多个线程，一个程序一般一个进程
class Single
{
private:
	int m_data;
	//不能有一个对象创建
	Single(){}
	Single(int data) :m_data(data) {}
	Single(const Single& ){}
	//-----
	static Single s_instance;//静态成员对象
public:
	static Single& get_instance()
	{
		return s_instance;
	}
};


//懒汉模式

