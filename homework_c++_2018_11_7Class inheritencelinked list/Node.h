#pragma once
#include<string>
#include<iostream>
using namespace std;
//����˼·������������һϵ�л���ָ�룬���ҵ���ӦID�Ľڵ��ʹ�û���ָ����ʳ��������ķ���

class Employee//�������
{
private:
	string m_name;//����
	string m_career;//ְҵ����
	double m_salary;//нˮ
public:
	
	Employee(string name="Nobody",string career="None"):m_name(name),m_career(career){ }//���๹�캯��
	void Name();
	void Salary(double salary);
	void Show();
	//�麯��---
	virtual void SetSalary() = 0;//���麯��
};
class Manager :public Employee//������
{
public:
	Manager(string name="Nobody",string career="Employee"):Employee(name,career){ }//�����๹�캯��
	//�麯��----
	virtual void SetSalary();//�������麯��ʵ��
};

class Technician :public Employee//������Ա��
{
public:
	Technician(string name = "Nobody", string career = "Technician"):Employee(name,career){ }//�����๹�캯��
	//�麯��----
	virtual void SetSalary();//�������麯��ʵ��,����ͳ��������ͬ
};

class SalesManager :public Employee//���۾�����
{
public:
	SalesManager(string name = "Nobody", string career = "SalesManager") :Employee(name, career) { }//�����๹�캯��
	//�麯��----
	virtual void SetSalary();//�������麯��ʵ��,����ͳ��������ͬ
};

class SalesMan :public Employee//����Ա��
{
public:
	SalesMan(string name = "Nobody", string career = "SalesManager") :Employee(name, career) { }//�����๹�캯��
	//�麯��----
	virtual void SetSalary();//�������麯��ʵ��,����ͳ��������ͬ
};
//struct node
//{
//	Employee* p;//�������ָ�룬ָ��������
//	int ID;
//	struct node* next;
//};
