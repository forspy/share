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
	void acquire(const std::string& co, long n, double pr);//获得股票
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