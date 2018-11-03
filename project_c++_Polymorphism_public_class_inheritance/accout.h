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
	//引用的另外一个好处是可以确保从虚函数受益（另外也可以节省内存和时间）
	2.方法在基类中被声明为虚方法后，在派生类中也将自动生成虚方法。（推荐在派生类中使用virtual显示地指出虚方法）
	//编译器在程序运行的时候选择正确的虚方法的代码被称为动态连编，隐式向上强制转化也会发生动态连编。
	//编译器对非虚方法使用静态连编，因为编译的时候已经知道左值的类型了
	//无论实不实现析构函数，在用作基类时，必须给该析构函数定义为虚函数（构造函数不用声明为虚的）
	//如果重新定义继承的方法，应确保与原来的原型完全相同（参数不同步构成重载，而是会隐藏调所有同名的基类方法），允许返回类型发生变化
	//如果基类声明有重载，则应在派生类中重新定义所有的基类版本(指的是如果使用virtual方法的话)
	//友元一般不是虚函数
	//
	////protected:在类外只能用公有类成员来访问protected部分保护的成员
      	//private和protected之间的区别只有在派生的基类中才会表现出来。
	//派生类的成员可以直接访问基类的保护成员protected，但不能访问基类的私有成员private
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

