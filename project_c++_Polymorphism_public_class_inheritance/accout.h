#pragma once
#include<string>
using namespace std;
class Brass
{
private:
	string fullname;//�ͻ�����
	long accout_num;//�˺�
	double balance;//����
public:
	Brass(const string& s = "NUllBODY", long an = -1, double bal = 0.0);
	
	//������ͬ�ķ������ڻ�������������
	void Deposit(double amt);//���
	double Balance() const;
	//�鷽��
	/*
	ΪʲôҪ��virtual�ؼ��֣�
	1.���û�м�virtual�����ҷ�����ͨ�����û�ָ������Ƕ�����õģ����򽫸����������ͻ�ָ������ѡ�񷽷�
	Brass A;
	BrassPlus B;
	Brass& c1=A;
	Brass* c2=B;
	c1.view_acct();//use Brass::view_acct()
	c2->view_acct();//use Brass::view_acct()
	2.�������virtual������ͨ�����û�ָ��ָ������Ͷ���ѡ�񷽷�
	Brass A;
	BrassPlus B;
	Brass& c1=A;
	Brass* c2=B;
	c1.view_acct();//use Brass::view_acct()
	c2->view_acct();//use BrassPlus::view_acct()
	2.�����ڻ����б�����Ϊ�鷽��������������Ҳ���Զ������鷽�������Ƽ�����������ʹ��virtual��ʾ��ָ���鷽����
	*/
	virtual void WithDraw(double amt);//ȡ��(�鷽��)
	/*
	ϣ��ͬһ��������������ͻ����е���Ϊ�ǲ�ͬ�ģ���������Ϊȡ���ڵ��ø÷����Ķ���--��̬
	��̬���м̳У�
	1.�������������¶������ķ���
	2.ʹ���鷽��
	*/
	virtual void ViewAcct()const;
	virtual ~Brass();//��������������ʱ��û�õ�����ʹ�ã�Ϊ��ȷ���ͷ���������ʱ������ȷ��˳�������������
};

class BrassPlus :public Brass
{
private:
	double max_loan;//͸֧����
	double rate;//��������
	double owes_bank;//Ƿ���ܶ�
public:
	BrassPlus(const string& s = "NULLBODY", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
	//�鷽��
	virtual void WithDraw(double amt);//ȡ��(�鷽��)
	virtual void ViewAcct()const;//��ʾ�˻�(�鷽��)
	//�����·���
	void Reset_max(double m) { max_loan = m; }
	void Reset_rate(double r) { rate = r; }
	void Reset_owes() { owes_bank = 0; }
};

