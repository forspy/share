#include<iostream>
#include"stock00.h"

void Stock::acquire(const std::string& co, long n, double pr)//1.Stock::(类+作用域解析运算符)表示该成员函数能够使用这个类的所有成员2.使用引用接住string对象
{
	company = co;
	if (n < 0)
	{
		std::cout << "持股数目不能为负数，设为0\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;//接住每股价格
	set_tot();//计算私有成员中total_val的总价格
}

void Stock::buy(long num, double price)//买入几股
{
	if (num < 0)
		std::cout << "买入不能为负数\n";
	else
	{
		shares += num;
		share_val = price;//股票现价
		set_tot();//重新计算
	}
}

void Stock::sell(long num, double price)//卖出几股
{
	using std::cout;//使用名称空间方便一点
	if (num < 0)
		cout << "卖出不能为负数\n";
	else if (num > shares)
		cout << "卖出数目不能大于现持数目\n";
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)//股价变动
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::endl;
	std::cout << "公司：" << company << endl
		<< "持股数：" << shares << endl
		<< "股价：" << share_val << endl
		<< "该股总价值" << total_val << endl;
}