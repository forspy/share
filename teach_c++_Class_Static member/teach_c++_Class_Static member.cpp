#include"Accout.h"

int main()
{
	Accout A("xiaoming", 11111, 12345, 3000);
	
	Accout::adjust();//静态成员函数不属于任何一个对象，就像银行调整利率跟对象无关，没有this指针
	
	//A.adjust();//3.当然通过对象去调用也行
	//Accout::m_rate;//4.public静态都可以这样调用	
	A.profit();
	A.show();
	//单例模式：有且只有一个对象。 比如任务管理器
}