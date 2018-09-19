#include<iostream>
#include"stock00.h"

int main()
{
	Stock business;//创建一个名为business的类对象
	//获得股票
	business.acquire("Qiushi", 100, 3);//调用Stock类的成员函数
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
}