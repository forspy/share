//ʵ��
#include"bank.h"
namespace ICBC
{
	Bank::Bank(double money)
	{
		balance = money;
	}
	Bank Bank::operator+(double add) const//����+
	{
		Bank temp;
		temp.balance = this->balance;
		temp.save(add);
		return temp;
	}
	Bank Bank::operator-(double minus) const//����-
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
	Bank Bank::operator+(double add) const//����+
	{
		Bank temp;
		temp.balance = this->balance;
		temp.save(add);
		return temp;
	}
	Bank Bank::operator-(double minus) const//����-
	{
		Bank temp;
		temp.balance = this->balance;
		temp.draw(minus);
		return temp;
	}
}
