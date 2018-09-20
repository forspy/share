#include<iostream>
#include"stock01.h"

int main()
{
	{
		//获得股票
		Stock business("qiushi",11,2.5);//隐式的创建一个名为business的类对象，并赋给这个对象初值，推荐	，使用默认参数型的构造函数   
		//business.show();
		//Stock business = Stock("qiushi", 11, 2.5);//显式的创建一个名为business的类对象，并赋给这个对象初值，需要赋值	
		business.show();
		//增持
		business.buy(10, 3.5);
		business.show();
		//减持
		business.sell(20, 3.3);
		business.show();
		//不增持也不减持
		business.update(3.6);
		business.show();
		Stock copy;//将使用重载型的默认构造函数
		copy = business;//对象可以拷贝，拷贝的原理是将该类的所有成员都拷贝到目标对象中，所以目标对象的成员都被替换了一遍，其中也包含析构函数，因此总体调用了析构函数两次
		copy.show();
		Stock* p = new Stock{ "test",10,10 };
		(*p).show();
		delete p;//不能用delete[] p
		//1.析构函数只会自动释放释放类里面定义的指向堆上的指针，类对象的指针需要自己使用delete释放完以后才会调用析构函数
		//2.析构函数的调用时间点时在类对象作用域完结时析构函数上场，因为指向堆的指针对象在堆上开辟内存，所以只有在该内存释放以后才会调用这个类指针的析构函数
	}//加这个大括号的目的时在这个代码段调用析构函数，使内存释放

}