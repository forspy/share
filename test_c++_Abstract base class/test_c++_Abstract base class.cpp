#include"AcctABC.h"
const int CLIENTS = 2;
int main()
{
	AcctABC* p_clients[CLIENTS];//申请一组抽象基类的指针数组
	p_clients[0] = new Brass("小明", 12345, 3000.0);
	p_clients[1] = new BrassPlus("小红",11222,4000.0);//后面采用默认透支上限和利率//经常看到默认的构造函数里参数有Brass&&是什么意思？
	
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();//分别调用对象类型的虚函数方法
		cout << endl;
	}
	p_clients[1]->WithDraw(4500);
	p_clients[1]->ViewAcct();
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}
}