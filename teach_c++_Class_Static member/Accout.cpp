#include "Accout.h"
//��̬����
double Accout::m_rate = 0.02;//ֻ����ʵ���ļ��˶���,����Ϊ˽����main���治�ܷ��ʣ���ȫ���ܷ���

//����ģʽ----
Single Single::s_instance(100);//ע����cppʵ��
//------------

//����ģʽ--
Singleton* Singleton::s_instance_p=NULL;//ע����cppʵ��һ��ʼ�ȸ�ֵNULL
//--------

void Accout::draw(double money)
{
	if (money > m_balance)
	{
		cout << "buzu" << endl;
		return;
	}
	m_balance -= money;
}

void Accout::profit()
{
	m_balance *= (1 + m_rate);
}

void Accout::show()
{
	cout << "����"<<m_name << endl;
	cout <<"�˺�"<< m_no << endl;
	cout << "���" << m_balance << endl;
}

void Accout::adjust(double value)
{
	//m_balance += 1;��̬�������ܷ��ʷǾ�̬��Ա��ֻ�ܷ��ʾ�̬��Ա	
	m_rate += value;
}

Accout::~Accout()
{
}
