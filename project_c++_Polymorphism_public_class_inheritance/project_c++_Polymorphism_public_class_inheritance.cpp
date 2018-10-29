#include"accout.h"
#include<iostream>

int main()
{
	Brass xiaowang("xiaowang", 12345, 4000.0);
	xiaowang.ViewAcct();
	xiaowang.WithDraw(4200);
	BrassPlus xiaoming("xiaoming", 11000, 2000.0);
	xiaoming.ViewAcct();
	xiaoming.Deposit(1000);
	xiaoming.WithDraw(3200);
	xiaoming.ViewAcct();
	//上述的多态性方法是由对象调用的
	//假设要管理Brass和BrassPlus的账户，使用数组来保存，但数组中的元素类型必须一致，所以创建了一个基类的指针数组
	//因为基类指针数组Brass指针既可以指向Brass对象，也可以指向BrassPlus派生类对象，因此使用一个指针数组来表示多种类型的对象就是多态性
	const int CLIENTS = 3;
	Brass* p_clients[CLIENTS];//创建一个指针数组
	p_clients[0] = new Brass("xiaozhang", 11111, 5000);
	p_clients[1] = new BrassPlus("xiaohong", 00001, 6666);
	p_clients[2] = new BrassPlus(*p_clients[0]);//利用现有对象构造基类
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];//如果析构函数不是虚的就只会调用Brass类的析构，如果是虚的就将调用指针指向对象类的析构即BrassPlus
	}
}