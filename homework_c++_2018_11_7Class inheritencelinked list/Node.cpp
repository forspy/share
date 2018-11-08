#include"Node.h"

void Employee::Name()
{
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	m_name = name;
}

void Employee::Salary(double salary)
{
	m_salary = salary;
}

void Employee::Show()
{
	cout << "职业类型为：" << m_career << endl;
	cout << "姓名为：" << m_name << endl;
	cout << "薪水为：" << m_salary << endl;
}

void Manager::SetSalary()
{
	Salary(8000);
}


void Technician::SetSalary()
{
	cout << "请输入Technician这个月工作了多少个小时" << endl;
	double hours;
	cin >> hours;
	Salary(100 * hours);
}

void SalesManager::SetSalary()
{
	cout << "请输入当月销售额" << endl;
	double sales;
	cin >> sales;
	Salary(5 * sales / 100.0 + 5000);
}

void SalesMan::SetSalary()
{
	cout << "请输入当月推销员的销售额" << endl;
	double sales;
	cin >> sales;
	Salary(5 * sales / 100.0 );
}
