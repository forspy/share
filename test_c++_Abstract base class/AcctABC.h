#pragma once
#include<iostream>
#include<string>
using namespace std;
class AcctABC//�������
{
private:
	string fullName;
	long acctNum;
	double balance;
protected:
	const string& FullName()const { return fullName; }
	long AcctNum()const { return acctNum; }
public:
	AcctABC(const string& s="nulbody",long an=-1,double bal=0.0);//ֻҪ�ṩ�˹��캯����Ĭ�Ϲ��캯������ʧ�ˣ������Ҫȫд��Ĭ�ϲ���
	void Deposit(double amt);
	double Balance()const { return balance; }

	virtual void WithDraw(double amt) = 0;//���麯��,��������ʵ�ֲ�����Ϊȱ�����ݳ�Ա������������������ʵ��
	virtual void ViewAcct()const = 0;

	virtual ~AcctABC();
};
//������Brass
class Brass :public AcctABC
{
public:
	Brass(const string& s="nullbody",long an=-1,double bal=0.0):AcctABC(s,an,bal){}//���ó������Ĺ��캯�����д��븴��
	virtual void WithDraw(double amt);
	virtual void ViewAcct()const;
	virtual ~Brass(){}
};
//������BrassPlus
class BrassPlus :public AcctABC
{
private:
	double maxLoan;//����������
	double rate;//��������
	double owesBank;//ǩ���ж��٣�������Ϣ��
public:
	BrassPlus(const string& s = "nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.1);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);//��������Brass
	virtual void ViewAcct()const;
	virtual void WithDraw(double amt);
	void ResetMax(double m) { maxLoan = m; }//��������������
	void ResetRate(double r) { rate = r; }//������Ϣ
	void ResetOwes() { owesBank = 0; }//����
};
//���е�Բ������Բ��Ҳ����Բ����Բ���Ӽ�����˸���is-a�Ĺ�ϵ������Բ������Բ
/*
����������ںܶ����⣺
1.��Բ��������Բ���������ꡢ�����ᡢ�̰��ᡢ����ǣ��������ƶ���Բ��������Բ�������ת��Բ�����ų�����Ͷ̰���
2.�������Բ����������Բ�࣬��ΪԲ��ֻ��Ҫһ���뾶���������꣬���������������Ա�ͷ�������Ҫ������������Ϣ����(��̳��ܲ��ܼ̳е������private��Ա��)
��tips:���һ������̳��˸��࣬��ô�������ӵ�и������еĳ�Ա���Ժͷ�������ʹ�Ǹ�������private���Եı���������Ҳ�Ǽ̳еģ�ֻ��������ʹ�ã�
Ҳ����˵�����̳��ˣ�����û��ʹ��Ȩ���ƺ��ֵ�ì�ܣ�������ͨ�׵�˵������ ֻ�ܿ��������ã�лл��
��Ȼ�����������ǣ����ǻ��ǿ���ͨ��set ��get�ķ�������ӵķ��ʸ����е�private���Եı��� лл��
���Գ���һ�ַ���������Բ��Բ�г�������ǵĹ��ԣ�����Щ���Էŵ�һ��ABC�У�Ȼ���ABC��������Բ��Բ�������ࣨ�����Ϳ���ʹ�û���ָ��ͬʱ����Բ����Բ�Ķ��󣬼�����ʹ�ö�̬�ķ�����

*/
//�������
class BaseEllipse
{
	//�����������������Ĺ�ͬ�㣺�������ꡢMove()������Area()����
private:
	double x;
	double y;
	//...
public:
	BaseEllipse(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	virtual~BaseEllipse() {}
	void Move(int nx, int ny) { x = nx; y = ny; }
	virtual double Area()const = 0;//���麯������Ȼ�����ڳ��������ʵ��Area�ķ�������Ϊ��û�а�����Ҫ�����ݳ�Ա�����麯�������ж��壩
								   //����C++ͨ��ʹ�ô��麯���ṩδʵ�ֵĺ���
								   //������һ����������б���Ҫ��һ�����麯������һ�����麯���ǳ������ı�־
};
//��֮�����Դӳ������BaseEllipse��������Բ��Ellipse���ԲCirle�࣬����ΪCirle���Ǳ�ʾԲ����Ellipse���Ա�ʾΪ��ԲҲ���Ա�ʾΪԲ����Ϊ���ڰ�����ϵ��
//����BaseEllipse�������ָ����������࣬�������������౻��Ϊ������