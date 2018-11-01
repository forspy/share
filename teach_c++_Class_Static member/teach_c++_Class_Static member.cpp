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
	//Single B(100);//这样是不行的，因为构造函数是私有的，所以只能用静态成员的方法去调用
	Single& s1 = Single::get_instance();
	Single& s2 = Single::get_instance();
	cout << "地址为" << endl;
	cout<< &s1 << endl ;
	cout << &s2 << endl;
	//所以这两个引用指向同一个对象，说明只能生成一个对象，这就形成了单例模式（饿汉模式）
	Singleton& s3 = Singleton::get_instance_p();
	Singleton& s4 = Singleton::get_instance_p();
	cout << "地址为" << endl;
	cout << &s3 << endl;
	cout << &s4 << endl;
	Singleton::clear();
	//定位new的时候使用过显式析构
}