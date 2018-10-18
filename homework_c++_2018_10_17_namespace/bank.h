#pragma once
#include<iostream>
namespace ICBC
{
	class Bank
	{
	private:
		double balance;//���
	public:
		//Bank();//���캯��
		Bank(double money = 2000);//���캯��Ĭ�ϲ�����
		//~Bank();//��������
		void save(double add) { balance = balance + add; }//��������
		Bank operator+(double add) const;
		void draw(double minus) { balance = balance - minus; }
		Bank operator-(double minus) const;
		void show();
	};
}
inline void ICBC::Bank::show()//��������
{
	std::cout << "ICBC�������е�ǰ���Ϊ" << ICBC::Bank::balance << std::endl;
}
namespace ABC
{
	class Bank
	{
	private:
		double balance;//���
	public:
		Bank(double money = 4000);//���캯��Ĭ�ϲ������ذ�
		void save(double add) { balance = balance + add; }//��������
		Bank operator+(double add) const;
		void draw(double minus) { balance = balance - minus; }
		Bank operator-(double minus) const;
		void show();
	};
}
inline void ABC::Bank::show()//��������
{
	std::cout << "ABCũҵ���е�ǰ���Ϊ" << ABC::Bank::balance << std::endl;
}