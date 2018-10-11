//static 修饰的函数和变量只能在该文件内部使用（基本）
//c++ static新增属性： 
//1.静态成员函数

//2.静态数据成员
#include<iostream>
#include"tree.h"

//
using namespace std;
class human
{
private:
	static int body;
	int foot;
public:
	static int head;//(1).声明一个静态类成员（static修饰的静态类成员变为全局变量）
	static void show();//静态成员函数
	void walk()//可以在类内部直接定义函数（不推荐）
	{
		human::body = 1;//使用类内部成员时推荐写上类名
	}
	void talk() const;//表示这个类成员函数不会修改使用它的对象的值
};

int human::head;//(2).定义一个类成员
extern "C"//如果调用的时C风格的函数可以使用该方法调用
{
	void human::show()//定义一个成员函数
	{
		//所以静态成员函数里也没有this指针
	}

}

void human::talk() const
{
	//this->foot = 1;const右端修饰的函数不能修改里面成员函数的值
	cout << this->foot << endl;//	只读可以
}

/*
第三部分：名称空间
为了解决不同厂商提供的相同函数名，第三方厂商一般会给自己的函数加上名称空间
*/
namespace A
{
	class human
	{
	public:
		int head;
	};
}
namespace B
{
	class human
	{
	public:
		int head;
	};
}

int main()
{
	human::head;//static修饰的静态类成员可以不需要借助类对象去访问，public可直接访问
	human::show();//静态成员函数可以当普通函数使用
	using namespace A;//后面的A名称空间可以不写，但B要写 注意作用域
	A::human A_company;
	A_company.head = 1;
	B::human B_company;
	B_company.head = 2;
}

