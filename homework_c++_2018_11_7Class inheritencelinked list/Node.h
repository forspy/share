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
	static double m_sales;//�����ܶ�
	static int m_id;//���
public:
	Employee(string name="Nobody",string career="None"):m_name(name),m_career(career){ }//���๹�캯��
	void Salary(double salary);
	double SetSales(double sales=0);
	void SetName();
	void SetID();
	void Show();//�鿴������Ϣ
	int ID();
	//�麯��---
	virtual void SetSalary() = 0;//���麯��
};
class Manager :public Employee//������
{
public:
	Manager(string name="Nobody",string career="����"):Employee(name,career){ }//�����๹�캯��
	//�麯��----
	virtual void SetSalary();//�������麯��ʵ��
};

class Technician :public Employee//������Ա��
{
public:
	Technician(string name = "Nobody", string career = "������Ա"):Employee(name,career){ }//�����๹�캯��
	//�麯��----
	virtual void SetSalary();//�������麯��ʵ��,����ͳ��������ͬ
};

class SalesManager :public Employee//���۾�����
{
public:
	SalesManager(string name = "Nobody", string career = "���۾���") :Employee(name, career) { }//�����๹�캯��
	//�麯��----
	virtual void SetSalary();//�������麯��ʵ��,����ͳ��������ͬ
};

class SalesMan :public Employee//����Ա��
{
public:
	SalesMan(string name = "Nobody", string career = "����Ա") :Employee(name, career) { }//�����๹�캯��
	//�麯��----
	virtual void SetSalary();//�������麯��ʵ��,����ͳ��������ͬ
};
//������ָ�뱣��������������Ͳ�ѯ��
//
struct node
{
	Employee* p;//�������ָ�룬ָ��������
	int id;//�ڵ�id��¼�ýڵ��id�����ྲ̬ID�����Ѿ��е�ID���ۼ�
	struct node* next;
};

//��ʼ��
void init();
//������Ϣ��ͷ�巨����һ������ָ�룩
void appendHead();
//��ʾ������Ϣ
void showAllNode();
//����ID����ʾ��Ϣ
void search();