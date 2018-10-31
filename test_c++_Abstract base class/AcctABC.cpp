#include "AcctABC.h"
//抽象基类实现
AcctABC::AcctABC(const string& s , long an , double bal )
{
	//以下写在初始化列表里也行
	fullName = s;
	acctNum = an;
	balance = bal;
}
void AcctABC::Deposit(double amt)//存入
{
	if (amt < 0)
		cout << "存入负数无效" << endl;
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
//派生Brass类实现
void Brass::WithDraw(double amt)//取出
{
	if (amt < 0)
		cout << "支出不能为负数" << endl;
	else if (amt <= Balance())//访问抽象基类的public方法
		Balance();//因为只有抽象基类有该方法，所以不加抽象基类限定符也可以
	else
		cout << "取出超出余额，无效" << endl;
}
void Brass::ViewAcct()const
{
	cout << "客户姓名：" << FullName() << endl;//因为是派生的，所以可以直接调用对象
	cout << "账号：" << AcctNum() << endl;
	cout << "结余：" << Balance() << endl;
}
//派生类BrassPlus实现
BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r) :AcctABC(s, an, bal)//构造函数
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :AcctABC(ba)//拷贝构造函数
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct()const
{
	cout << "客户姓名：" << FullName() << endl;//因为是派生的，所以可以直接调用对象
	cout << "账号：" << AcctNum() << endl;
	cout << "结余：" << Balance() << endl;
	//Brass::ViewAcct();//但是不能调用Brass的public方法，因为不是派生关系,即便是声明为友元，也需要创建对象调用方法
	cout << "最大贷款数：" << maxLoan << endl;
	cout << "欠银行：" << owesBank << endl;
	cout << "贷款利率：" << 100 * rate << "%" << endl;
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
		cout << "客户："<<FullName() << endl;
		cout << "透支：" << advance << endl;
		cout << "利息：" << advance*rate << endl;
		Deposit(advance);
		AcctABC::WithDraw(amt);
	}
	else
	{
		cout << "以达透支上限，无法透支" << endl;
	}

}