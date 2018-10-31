#include "AcctABC.h"
//�������ʵ��
AcctABC::AcctABC(const string& s , long an , double bal )
{
	//����д�ڳ�ʼ���б���Ҳ��
	fullName = s;
	acctNum = an;
	balance = bal;
}
void AcctABC::Deposit(double amt)//����
{
	if (amt < 0)
		cout << "���븺����Ч" << endl;
	else
		balance += amt;
}
void AcctABC::WithDraw(double amt)
{
	balance -= amt;
}

AcctABC::~AcctABC()
{
}
//����Brass��ʵ��
void Brass::WithDraw(double amt)//ȡ��
{
	if (amt < 0)
		cout << "֧������Ϊ����" << endl;
	else if (amt <= Balance())//���ʳ�������public����
		Balance();//��Ϊֻ�г�������и÷��������Բ��ӳ�������޶���Ҳ����
	else
		cout << "ȡ����������Ч" << endl;
}
void Brass::ViewAcct()const
{
	cout << "�ͻ�������" << FullName() << endl;//��Ϊ�������ģ����Կ���ֱ�ӵ��ö���
	cout << "�˺ţ�" << AcctNum() << endl;
	cout << "���ࣺ" << Balance() << endl;
}
//������BrassPlusʵ��
BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r) :AcctABC(s, an, bal)//���캯��
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :AcctABC(ba)//�������캯��
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct()const
{
	cout << "�ͻ�������" << FullName() << endl;//��Ϊ�������ģ����Կ���ֱ�ӵ��ö���
	cout << "�˺ţ�" << AcctNum() << endl;
	cout << "���ࣺ" << Balance() << endl;
	//Brass::ViewAcct();//���ǲ��ܵ���Brass��public��������Ϊ����������ϵ,����������Ϊ��Ԫ��Ҳ��Ҫ����������÷���
	cout << "����������" << maxLoan << endl;
	cout << "Ƿ���У�" << owesBank << endl;
	cout << "�������ʣ�" << 100 * rate << "%" << endl;
}
void BrassPlus::WithDraw(double amt)
{
	double bal = Balance();
	if (amt <= bal)
		AcctABC::WithDraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank = advance*(1 + rate);
		cout << "�ͻ���"<<FullName() << endl;
		cout << "͸֧��" << advance << endl;
		cout << "��Ϣ��" << advance*rate << endl;
		Deposit(advance);
		AcctABC::WithDraw(amt);
	}
	else
	{
		cout << "�Դ�͸֧���ޣ��޷�͸֧" << endl;
	}

}