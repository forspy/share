#pragma once
#include<iostream>
namespace ICBC
{
	class Bank
	{
	private:
		double balance;//存款
	public:
		//Bank();//构造函数
		Bank(double money = 2000);//构造函数默认参数版
		//~Bank();//析构函数
		void save(double add) { balance = balance + add; }//内联函数
		Bank operator+(double add) const;
		void draw(double minus) { balance = balance - minus; }
		Bank operator-(double minus) const;
		void show();
	};
}
inline void ICBC::Bank::show()//内联函数
{
	std::cout << "ICBC工商银行当前存款为" << ICBC::Bank::balance << std::endl;
}
namespace ABC
{
	class Bank
	{
	private:
		double balance;//存款
	public:
		Bank(double money = 4000);//构造函数默认参数重载版
		void save(double add) { balance = balance + add; }//内联函数
		Bank operator+(double add) const;
		void draw(double minus) { balance = balance - minus; }
		Bank operator-(double minus) const;
		void show();
	};
}
inline void ABC::Bank::show()//内联函数
{
	std::cout << "ABC农业银行当前存款为" << ABC::Bank::balance << std::endl;
}