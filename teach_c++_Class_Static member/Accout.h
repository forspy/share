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
	//私有了以后，构造函数就不能被外部调用，从而不能有任何一个对象创建
	//把所有的构造函数写为私有，防止默认函数
	Single(){}
	Single(int data) :m_data(data) {}
	Single(const Single& ){}
	//-----
	//1.人为创建一个例外的静态对象，2.程序进程一开始就存在了3.但是是私有的拿不到
	static Single s_instance;//静态成员对象
public:
	//写一个公有的方法去获取私有成员对象
	static Single& get_instance()
	{
		return s_instance;
	}
};

//懒汉模式（随用随创建）

class Singleton
{
private:
	int m_data;
	//私有了以后，构造函数就不能被外部调用，从而不能有任何一个对象创建
	//把所有的构造函数写为私有，防止默认函数
	Singleton() {}
	Singleton(int data) :m_data(data) {}
	Singleton(const Singleton&) {}
	//-----
	//1.人为创建一个例外的静态对象，2.程序进程一开始就存在了3.但是是私有的拿不到
	static Singleton* s_instance_p;//静态成员对象指针
public:
	//写一个公有的方法去获取私有成员对象
	static Singleton& get_instance_p()
	{
		if (!s_instance_p)//如果为空则开辟内存
		{
			s_instance_p = new Singleton(100);
		}
		return *s_instance_p;
	}
	//因为对象没法生成，所以也没法销毁就不会自动调用析构函数，可以手动调用析构函数
	static void clear()//释放静态成员必须用静态函数
	{
		if (s_instance_p)
		{
			delete s_instance_p;
			s_instance_p = NULL;
		}
	}
};
