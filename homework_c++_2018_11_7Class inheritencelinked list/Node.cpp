#include"Node.h"

void Employee::Name()
{
	cout << "������������" << endl;
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
	cout << "ְҵ����Ϊ��" << m_career << endl;
	cout << "����Ϊ��" << m_name << endl;
	cout << "нˮΪ��" << m_salary << endl;
}

void Manager::SetSalary()
{
	Salary(8000);
}


void Technician::SetSalary()
{
	cout << "������Technician����¹����˶��ٸ�Сʱ" << endl;
	double hours;
	cin >> hours;
	Salary(100 * hours);
}

void SalesManager::SetSalary()
{
	cout << "�����뵱�����۶�" << endl;
	double sales;
	cin >> sales;
	Salary(5 * sales / 100.0 + 5000);
}

void SalesMan::SetSalary()
{
	cout << "�����뵱������Ա�����۶�" << endl;
	double sales;
	cin >> sales;
	Salary(5 * sales / 100.0 );
}
