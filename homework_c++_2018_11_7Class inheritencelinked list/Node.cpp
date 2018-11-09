#include"Node.h"

double Employee::m_sales = 0;//��ʼ����̬��Ա
int Employee::m_id = 10000;

void Employee::SetName()
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

double Employee::SetSales(double sales)
{
	m_sales += sales;//�ۼ�
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
	cout << "ְҵ����Ϊ��" << m_career << endl;
	cout << "����Ϊ��" << m_name << endl;
	cout << "нˮΪ��" << m_salary << endl;
	cout << endl;
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
	double temp_sales=SetSales();
	Salary(5 * temp_sales / 100.0 + 5000);
}

void SalesMan::SetSalary()
{
	cout << "�����뵱������Ա�����۶�" << endl;
	double sales;
	cin >> sales;
	Salary(4 * sales / 100.0 );
	SetSales(sales);//�ۼ����۶�����۾���
}
//����һ������ͷ
struct node head;
//��ʼ��
void init()
{
	head.p = NULL;
	head.next = NULL;
}
//����4��������ȫ�ֶ���
Manager manager;//1
Technician technician;//2
SalesMan salesman;//3
SalesManager salesmanager;//4
//������Ϣ��ͷ�巨����һ������ָ�룩
void appendHead()
{
	//1.����һ���ڵ�
	struct node* newNode = new node;
	//����ڴ治��������
	if (newNode == NULL)
		return;
	//2.�Խڵ㸳ֵ
	
	cout << "������Ҫ¼���ְҵ���ͣ�" << endl;
	cout << "1.���� 2.������Ա 3.����Ա 4.���۾���(����Ӧ����¼��)" << endl;
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
	newNode->id = newNode->p->ID();//�����ڻ����н�ID��Ϊ��̬
	newNode->next = NULL;//�ڵ�β����ֵNULL
	//3.����
	struct node* ptr = &head;//����head��ȫ�ֱ���������һ��ָ��ͷ����ָ��ptr
	newNode->next = ptr->next;
	ptr->next = newNode;
}

//��ʾ������Ϣ
void showAllNode()
{
	struct node* ptr = &head;
	while (ptr->next)
	{
		ptr = ptr->next;
		cout << "IDΪ��" << ptr->id << endl;//��ʾ�ڵ����id
		ptr->p->Show();
	}
}
//����ID����ʾ��Ϣ
void search()
{
	int number;
	cout << "������Ҫ���ҵı�ţ�" << endl;
	cin >> number;
	struct node* ptr = &head;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->id == number)
		{
			cout << "�ҵ��˸���Ϣ��" << endl;
			ptr->p->Show();
			return;
		}
	}
	cout << "û���ҵ�����Ϣ��" << endl;
}