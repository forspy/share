#pragma once
#include<string>
#include<iostream>
using namespace std;
class Accout
{
private:
	string m_name;//�˻���
	int m_no;//�˺�
	int m_pwd;//
	double m_balance;
	
public:
	static double m_rate;//1.�������ʣ�2.��̬��Ա,��̬��Ա������sizeof��3.��ͨ��Ա���ڹ����ʱ�����
	Accout(string name="nobody",int no=0,int pwd=0,double balance=0):m_name(name),m_no(no),m_pwd(pwd),m_balance(balance){}
	void save(double money) { m_balance += money; }
	void draw(double money);
	void profit();//����Ϣ
	void show();
	static void adjust(double value=0.01);
	~Accout();
};
//����ģʽ(�ô����̳߳ء��ڴ�ػ�����)
//����ģʽ�����������ʹ�����
//һ�������ж���̣߳�һ������һ��һ������
class Single
{
private:
	int m_data;
	//������һ�����󴴽�
	Single(){}
	Single(int data) :m_data(data) {}
	Single(const Single& ){}
	//-----
	static Single s_instance;//��̬��Ա����
public:
	static Single& get_instance()
	{
		return s_instance;
	}
};


//����ģʽ

