#include"Node.h"

int main()
{
	Manager a("Joker");
	a.SetSalary();
	a.Show();
	Technician b;
	Employee* p = &b;
	p->Name();
	p->SetSalary();
	p->Show();
	SalesManager c;
	p = &c;
	p->Name();
	p->SetSalary();//注意经理拿的时销售总额，考虑用静态或node里面的全局变量
	p->Show();
	SalesMan d;
	p = &d;
	p->Name();
	p->SetSalary();
	p->Show();
}