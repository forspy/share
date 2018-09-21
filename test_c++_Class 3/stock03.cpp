#include<iostream>
#include"stock03.h"

//构造函数，实现部分（方式：重载）
Stock::Stock()//构造函数没有返回值
{
	std::cout << "调用默认构造函数\n";
	company = "No company";
	shares = 0;
	share_val = 0.0;
	set_tot();
}
Stock::Stock(const std::string& co, long n, double pr)//1.Stock::(类+作用域解析运算符)表示该成员函数能够使用这个类的所有成员2.使用引用接住string对象
{
	//std::cout << "使用公司名（第一个参数），采用默认参数的方式调用构造函数\n";
	company = co;
	if (n < 0)
	{
		std::cout << "持股数目不能为负数，设为0\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;//接住每股价格
	set_tot();//计算私有成员中total_val的总价格
}
//析构函数的实现
Stock::~Stock()
{
	std::cout << "Done!\n";//这里虽然没有使用new开辟内存，所以析构函数不会发挥很大作用，但至少可以看到Stock的对象的生命周期
}
//Stock::(类+作用域解析运算符)表示该成员函数能够使用这个类的所有成员2.使用引用接住string对象
void Stock::buy(long num, double price)//买入几股
{
	if (num < 0)
		std::cout << "买入不能为负数\n";
	else
	{
		shares += num;
		share_val = price;//股票现价
		set_tot();//重新计算
	}
}

void Stock::sell(long num, double price)//卖出几股
{
	using std::cout;//使用名称空间方便一点
	if (num < 0)
		cout << "卖出不能为负数\n";
	else if (num > shares)
		cout << "卖出数目不能大于现持数目\n";
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)//股价变动
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	using std::endl;
	std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);//保存默认输出格式
																								   //std是名称空间，ios_base是名称空间下的类，ftmflags是该类下的一种类型 orig是变量储存了输出格式  fixed是保持小数输出，floatfield包含定点表示和科学表示
	std::streamsize prec = std::cout.precision(3);//记录默认输出小数点后三位
	std::cout << "公司：" << company << endl
		<< "持股数：" << shares << endl
		<< "股价：" << share_val << endl;
	std::cout.precision(2);//以小数点后两位输出总价
	std::cout << "该股总价值" << total_val << endl;
	//还原默认设置
	std::cout.setf(orig);
	std::cout.precision(prec);
}

//利用this指针，比较两个对象中的较大值，返回一个该对象的引用（就为了省一个参数...niub）
//1.this指针用来指向调用成员函数的对象
//2.通过指针来访问结构成员同样适用于类成员(重要)
const Stock& Stock::topval(const Stock& s) const//如果希望成员函数对多个对象进行操作，可将额外对象作为参数传递给成员函数
{
	if (s.total_val > total_val)//其实total_val为this->total_val
		return s;
	else
		return *this;//返回调用成员函数的对象
}
