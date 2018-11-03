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
	friend ostream& operator<<(ostream& os, const lacksDMA& rs);
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
