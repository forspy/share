#pragma once
#include<string>
using namespace std;
class Brass
{
private:
	string fullname;//客户姓名
	long accout_num;//账号
	double balance;//结余
public:
	Brass(const string& s = "NUllBODY", long an = -1, double bal = 0.0);
	
	//对于相同的方法，在基类中声明即可
	void Deposit(double amt);//存款
	double Balance() const;
	//虚方法
	/*
	为什么要加virtual关键字？
	1.如果没有加virtual，并且方法是通过引用或指针而不是对象调用的，程序将根据引用类型或指针类型选择方法
	Brass A;
	BrassPlus B;
	Brass& c1=A;
	Brass* c2=B;
	c1.view_acct();//use Brass::view_acct()
	c2->view_acct();//use Brass::view_acct()
	2.如果加了virtual，程序将通过引用或指针指向的类型对象选择方法
	Brass A;
	BrassPlus B;
	Brass& c1=A;
	Brass* c2=B;
	c1.view_acct();//use Brass::view_acct()
	c2->view_acct();//use BrassPlus::view_acct()
	2.方法在基类中被声明为虚方法后，在派生类中也将自动生成虚方法。（推荐在派生类中使用virtual显示地指出虚方法）
	//编译器在程序运行的时候选择正确的虚方法的代码被称为动态连编，隐式向上强制转化也会发生动态连编。
	//编译器对非虚方法使用静态连编，因为编译的时候已经知道左值的类型了
	*/
	virtual void WithDraw(double amt);//取出(虚方法)
	/*
	希望同一个方法在派生类和基类中的行为是不同的，方法的行为取决于调用该方法的对象--多态
	多态公有继承：
	1.在派生类中重新定义基类的方法
	2.使用虚方法
	*/
	virtual void ViewAcct()const;
	virtual ~Brass();//虚析构函数，暂时还没用到，待使用，为了确保释放派生对象时，按正确的顺序调用析构函数
};

class BrassPlus :public Brass
{
private:
	double max_loan;//透支上限
	double rate;//贷款利率
	double owes_bank;//欠款总额
public:
	BrassPlus(const string& s = "NULLBODY", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
	//虚方法
	virtual void WithDraw(double amt);//取款(虚方法)
	virtual void ViewAcct()const;//显示账户(虚方法)
	//派生新方法
	void Reset_max(double m) { max_loan = m; }
	void Reset_rate(double r) { rate = r; }
	void Reset_owes() { owes_bank = 0; }
};

