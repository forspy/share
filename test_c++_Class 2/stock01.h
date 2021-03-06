#pragma once
#include<string>

class Stock//声明一个类
{
private://私有成员  对外数据隐藏 只有公有成员能访问（封装的一种）
		//数据想通常放在私有部分
	std::string company;//公司名称
	long shares;//所持股票数量
	double share_val;//每股的价格
	double total_val;//总价格
	void set_tot() { total_val = shares*share_val; };//成员函数  可以就地定义，也可以用原型表示（稍后实现）
													 //set_tot()属于内联函数 内联函数：定义在类声明中的函数，通常短小精悍
public://公有成员  对外接口
	   //组成类的接口函数放在共有部分


	//--------定义构造函数来初始化Stock类的成员数据
	Stock();//通过函数重载的方式先声明，在实现.cpp部分赋初值（两种默认方式可以只使用一种，推荐使用默认参数方式）

	//推荐采用默认函数的方式
	//以默认参数的方式，给已有的构造函数的所有参数提供默认值
	Stock(const std::string& co , long n = 0, double pr = 0.0);//构造函数的函数名要与类名一致


	//-------申明析构函数,
	//析构函数的作用：
	//1.跟踪对象，直到其过期为止
	//2.完成清理工作：如果静态对象在程序结束时调用；如果自动对象在代码块结束时调用；如果对象通过new创建，当使用delete删除内存时调用析构函数
	//3.类对象在过期时析构函数将自动被调用，如果没有析构函数，编译器将自动隐式声明一个析构函数
	~Stock();
	//void acquire(const std::string& co, long n, double pr);//获得股票---version1 因为有了构造函数，相当于对Stock类里面的成员赋初值，所以代替了acquire的功能
	void buy(long num, double price);//增持
	void sell(long num, double price);//卖出股票
	void update(double price);//更新股价
	void show();//显示持股信息
};
/* 也可以使用inline定义内联函数
inline void Stock::set_tot()
{
total_val = shares*share_val;
}
*/