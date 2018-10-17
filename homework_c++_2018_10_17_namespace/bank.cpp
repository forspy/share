//实现
#include"bank.h"
namespace ICBC
{
	Bank::Bank(double money)
	{
		balance = money;
	}
	Bank Bank::operator+(double add) const//重载+
	{
		Bank temp;
		temp.balance = this->balance;
		temp.save(add);
		return temp;
	}
	Bank Bank::operator-(double minus) const//重载-
	{
		Bank temp;
		temp.balance = this->balance;
		temp.draw(minus);
		return temp;
	}
}
namespace ABC
{
	Bank::Bank(double money)
	{
		balance = money;
	}
	Bank Bank::operator+(double add) const//重载+
	{
		Bank temp;
		temp.balance = this->balance;
		temp.save(add);
		return temp;
	}
	Bank Bank::operator-(double minus) const//重载-
	{
		Bank temp;
		temp.balance = this->balance;
		temp.draw(minus);
		return temp;
	}
}
