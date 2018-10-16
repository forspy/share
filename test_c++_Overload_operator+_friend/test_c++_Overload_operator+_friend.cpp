#include<iostream>
#include"overload.h"

int main()
{
	//测试类
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planing time=";
	planning.show();
	cout << endl;

	cout << "coding time=";
	coding.show();
	cout << endl;

	cout << "fixing time=";
	fixing.show();
	cout << endl;

	//total = coding.sum(fixing);//用的是coding对象的minutes
	total = coding + fixing;//为Time类添加了+运算（+类似函数重载）等价于total = coding.operator+(fixing);
	Time together;
	together = total + coding + fixing;//也可以多个相加相当于total.operator+(coding+fixing)
	
	cout << "coding.sum(fixing)=";
	total.show();
	cout << endl;

	total = total - fixing;
	cout << "total - fixing=";
	total.show();
	cout << endl;

	total = total * 2;
	cout << "total*2=";
	total.show();
	cout << endl;
	
	coding = 2 * coding;//当写完友元函数后可以使用交换律了,友元是类接口的扩展
	//coding = operator*(2, coding);//等价
	cout << "2*coding=";
	total.show();
	cout << endl;
}