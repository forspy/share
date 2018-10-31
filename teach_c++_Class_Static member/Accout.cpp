#include "Accout.h"


double Accout::m_rate = 0.02;//只能在实现文件了定义
//饿汉模式----
Single Single::s_instance(100);//注意在cpp实现
//------------
void Accout::draw(double money)
{
	if (money > m_balance)
	{
		cout << "buzu" << endl;
		return;
	}
	m_balance -= money;
}

void Accout::profit()
{
	m_balance *= (1 + m_rate);
}

void Accout::show()
{
	cout << "户名"<<m_name << endl;
	cout <<"账号"<< m_no << endl;
	cout << "余额" << m_balance << endl;
}

void Accout::adjust(double value)
{
	//m_balance += 1;非静态函数不能访问非静态成员，只能访问静态成员	
	m_rate += value;
}

Accout::~Accout()
{
}
