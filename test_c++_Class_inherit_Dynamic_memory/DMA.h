#pragma once
#include<iostream>
using namespace std;
class baseDMA
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = "null", int r = 0);//默认构造
	baseDMA(const baseDMA& rs);//拷贝构造
	virtual ~baseDMA();//虚析构
	baseDMA& operator=(const baseDMA& rs);//=重载拷贝构造
	friend ostream& operator<<(ostream& os, const baseDMA& rs);//友元<<重载
};

class lacksDMA :public baseDMA//公有继承
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];//设置一个39个char类型的字符串
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);//默认构造
	//小总结：如果没有构造函数，将生成默认构造函数，该默认构造函数将会调用基类构造函数
	//派生类构造函数的成员初始化列表没有显式调用基类构造函数，则编译器将隐式使用基类的默认构造函数来当作初始化列表来构造基类部分（前提是基类得有构造函数）
	//如果已经定义了某种构造函数，编译器将不会定义默认构造函数
	//提供构造函数的目的是使得所有成员能够被正确的初始化
	lacksDMA(const char* c, const baseDMA& rs);//基类拷贝构造
	//小总结：
	//在下述情况下，将使用拷贝构造函数
	//1.将新的对象初始化为同类
	//2.传递对象给参数
	//3.函数按值返回
	//4.编译器生成临时对象
	//小tips:
	//例如 baseDMA A;
	//A="HELLO"; 这里先使用了构造函数 baseDMA::baseDMA（const char*）生成一个临时对象，再调用baseDMA::operator=重载函数复制。
	//构造函数不能被继承，析构函数也不能被继承，赋值运算符不能被继承？可以基类对象=派生类对象但是只是调用基类的=运算符，不可以派生类=基类，因为派生类引用无法接住基类对象
	friend ostream& operator<<(ostream& os, const lacksDMA& rs);
	//友元函数是不能继承的，如果想使用基类友元可以使用例如：(const baseDMA&)hs派生类强转基类引用或者强转基类指针的方式来使用基类的友元函数
	//也可以使用os<<dynamic_cast<const baseDMA&>(hs);来强制类型转换
	//不需要析构函数
};

class hasDMA :public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);//默认拷贝构造
	hasDMA(const char* s, const baseDMA& rs);//基类拷贝构造
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& hs);
	friend ostream& operator<<(ostream& os, const hasDMA& hs);
};
