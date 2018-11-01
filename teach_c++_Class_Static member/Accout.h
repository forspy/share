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
	//˽�����Ժ󣬹��캯���Ͳ��ܱ��ⲿ���ã��Ӷ��������κ�һ�����󴴽�
	//�����еĹ��캯��дΪ˽�У���ֹĬ�Ϻ���
	Single(){}
	Single(int data) :m_data(data) {}
	Single(const Single& ){}
	//-----
	//1.��Ϊ����һ������ľ�̬����2.�������һ��ʼ�ʹ�����3.������˽�е��ò���
	static Single s_instance;//��̬��Ա����
public:
	//дһ�����еķ���ȥ��ȡ˽�г�Ա����
	static Single& get_instance()
	{
		return s_instance;
	}
};

//����ģʽ�������洴����

class Singleton
{
private:
	int m_data;
	//˽�����Ժ󣬹��캯���Ͳ��ܱ��ⲿ���ã��Ӷ��������κ�һ�����󴴽�
	//�����еĹ��캯��дΪ˽�У���ֹĬ�Ϻ���
	Singleton() {}
	Singleton(int data) :m_data(data) {}
	Singleton(const Singleton&) {}
	//-----
	//1.��Ϊ����һ������ľ�̬����2.�������һ��ʼ�ʹ�����3.������˽�е��ò���
	static Singleton* s_instance_p;//��̬��Ա����ָ��
public:
	//дһ�����еķ���ȥ��ȡ˽�г�Ա����
	static Singleton& get_instance_p()
	{
		if (!s_instance_p)//���Ϊ���򿪱��ڴ�
		{
			s_instance_p = new Singleton(100);
		}
		return *s_instance_p;
	}
	//��Ϊ����û�����ɣ�����Ҳû�����پͲ����Զ��������������������ֶ�������������
	static void clear()//�ͷž�̬��Ա�����þ�̬����
	{
		if (s_instance_p)
		{
			delete s_instance_p;
			s_instance_p = NULL;
		}
	}
};
