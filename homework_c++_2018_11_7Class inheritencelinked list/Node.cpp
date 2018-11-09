#include"Node.h"

double Employee::m_sales = 0;//初始化静态成员
int Employee::m_id = 10000;

void Employee::SetName()
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

double Employee::SetSales(double sales)
{
	m_sales += sales;//累计
	return m_sales;
}

void Employee::SetID()
{
	m_id++;
}

int Employee::ID()
{
	return m_id;
}

void Employee::Show()
{
	cout << "职业类型为：" << m_career << endl;
	cout << "姓名为：" << m_name << endl;
	cout << "薪水为：" << m_salary << endl;
	cout << endl;
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
	double temp_sales=SetSales();
	Salary(5 * temp_sales / 100.0 + 5000);
}

void SalesMan::SetSalary()
{
	cout << "请输入当月推销员的销售额" << endl;
	double sales;
	cin >> sales;
	Salary(4 * sales / 100.0 );
	SetSales(sales);//累计销售额给销售经理
}
//声明一个链表头
struct node head;
//初始化
void init()
{
	head.p = NULL;
	head.next = NULL;
}
//定义4个派生类全局对象
Manager manager;//1
Technician technician;//2
SalesMan salesman;//3
SalesManager salesmanager;//4
//插入信息（头插法插入一个基类指针）
void appendHead()
{
	//1.申请一个节点
	struct node* newNode = new node;
	//如果内存不够，返回
	if (newNode == NULL)
		return;
	//2.对节点赋值
	
	cout << "请输入要录入的职业类型：" << endl;
	cout << "1.经理 2.技术人员 3.推销员 4.销售经理(按对应数字录入)" << endl;
	int sort;
	cin >> sort;
	switch (sort)
	{
	case 1:
		newNode->p = &manager;
		newNode->p->SetName();
		newNode->p->SetSalary();
		newNode->p->SetID();
		break;
	case 2:
		newNode->p = &technician;
		newNode->p->SetName();
		newNode->p->SetSalary();
		newNode->p->SetID();
		break;
	case 3:
		newNode->p = &salesman;
		newNode->p->SetName();
		newNode->p->SetSalary();
		newNode->p->SetID();
		break;
	case 4:
		newNode->p = &salesmanager;
		newNode->p->SetName();
		newNode->p->SetSalary();
		newNode->p->SetID();
		break;
	default:
		break;
	}
	newNode->id = newNode->p->ID();//考虑在基类中将ID设为静态
	newNode->next = NULL;//节点尾部赋值NULL
	//3.链接
	struct node* ptr = &head;//由于head是全局变量，定义一个指向头部的指针ptr
	newNode->next = ptr->next;
	ptr->next = newNode;
}

//显示所有信息
void showAllNode()
{
	struct node* ptr = &head;
	while (ptr->next)
	{
		ptr = ptr->next;
		cout << "ID为：" << ptr->id << endl;//显示节点类的id
		ptr->p->Show();
	}
}
//查找ID，显示信息
void search()
{
	int number;
	cout << "请输入要查找的编号：" << endl;
	cin >> number;
	struct node* ptr = &head;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->id == number)
		{
			cout << "找到了该信息！" << endl;
			ptr->p->Show();
			return;
		}
	}
	cout << "没有找到该信息！" << endl;
}