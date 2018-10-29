#include "accout.h"
#include<iostream>


inline Brass::Brass(const string & s, long an, double bal)
{
	fullname = s;
	accout_num = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "����������Ч" << endl;
	else
		balance += amt;
}

double Brass::Balance() const
{
	return balance;
}



void Brass::WithDraw(double amt)
{
	if (amt < 0)
		cout << "ȡ��������������������Ч" << endl;
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "ȡ�������ڴ������������Ч" << endl;
}



void Brass::ViewAcct() const
{
	cout << "�ͻ�������" << fullname << endl;
	cout << "�˺ţ�" << accout_num << endl;
	cout << "���ࣺ" << balance << endl;
}

Brass::~Brass()
{
}

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r):Brass(s,an,bal)//���ó�ʼ���б����ȹ�����ࡣע��ֻ�й��캯������ʹ�ó�ʼ���б�
{
	max_loan = ml;
	owes_bank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r):Brass(ba)//��ʽ����Brss�������캯����һ�������ʼ������
{
	max_loan = ml;
	owes_bank = 0.0;
	rate = r;
}

void BrassPlus::WithDraw(double amt)
{
	double bal = Balance();
	if (amt <= bal)
		Brass::WithDraw(amt);//��ʵ�ֵ�ģ�飬���û��๫�з��������л���::������������ᵱ�������෽������
	else if (amt <= bal + max_loan - owes_bank)
	{
		double advance = amt - bal;//͸֧����
		owes_bank += advance*(1 + rate);
		cout << "͸֧�ˣ�" << advance << endl;
		cout << "��ϢΪ��" << advance*rate << endl;
		//�����������Ϊ��ʹbalance=0;
		Deposit(advance);
		Brass::WithDraw(amt);
		//��Ϊ���м̳�ֻ�ܼ̳е������public��Ա�����ʲ���private��Աbalance,�����಻���Է��ʻ���private��Ա����Ҫ��ֻ��ͨ�����෽��
	}
	else
		cout << "��Ǯ��͸֧��" << endl;
}

void BrassPlus::ViewAcct() const
{
	Brass::ViewAcct();
	cout << "�����" << max_loan << endl;
	cout << "Ƿ����:"<<owes_bank << endl;
	cout << "�������ʣ�" << 100 * rate << "%" << endl;
}
