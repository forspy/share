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
	p->SetSalary();//ע�⾭���õ�ʱ�����ܶ�����þ�̬��node�����ȫ�ֱ���
	p->Show();
	SalesMan d;
	p = &d;
	p->Name();
	p->SetSalary();
	p->Show();
}