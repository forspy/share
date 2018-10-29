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
		cout << "负数存入无效" << endl;
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
		cout << "取出必须是正数，操作无效" << endl;
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "取款数大于存款数，操作无效" << endl;
}



void Brass::ViewAcct() const
{
	cout << "客户姓名：" << fullname << endl;
	cout << "账号：" << accout_num << endl;
	cout << "结余：" << balance << endl;
}

Brass::~Brass()
{
}

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r):Brass(s,an,bal)//利用初始化列表优先构造基类。注：只有构造函数才能使用初始化列表
{
	max_loan = ml;
	owes_bank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r):Brass(ba)//隐式调用Brss拷贝构造函数用一个对象初始化基类
{
	max_loan = ml;
	owes_bank = 0.0;
	rate = r;
}

void BrassPlus::WithDraw(double amt)
{
	double bal = Balance();
	if (amt <= bal)
		Brass::WithDraw(amt);//在实现的模块，调用基类公有方法必须有基类::，否则编译器会当作派生类方法处理
	else if (amt <= bal + max_loan - owes_bank)
	{
		double advance = amt - bal;//透支部分
		owes_bank += advance*(1 + rate);
		cout << "透支了：" << advance << endl;
		cout << "利息为：" << advance*rate << endl;
		//下面两句就是为了使balance=0;
		Deposit(advance);
		Brass::WithDraw(amt);
		//因为公有继承只能继承到基类的public成员，访问不了private成员balance,派生类不可以访问基类private成员，重要，只能通过基类方法
	}
	else
		cout << "无钱可透支了" << endl;
}

void BrassPlus::ViewAcct() const
{
	Brass::ViewAcct();
	cout << "最大贷款：" << max_loan << endl;
	cout << "欠银行:"<<owes_bank << endl;
	cout << "贷款利率：" << 100 * rate << "%" << endl;
}
