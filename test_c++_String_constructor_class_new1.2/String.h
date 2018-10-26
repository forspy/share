#pragma once
#include<iostream>
#include<string>
using namespace std;
class String
{
private:
	//c++11支持类内成员初始化，如:int len=0;这与成员初始化列表等价
	static int num;//静态成员
	int len;
	string* str;//因为需要在堆上开内存，所以需要一个string*的指针
	//如果类中的指针成员是new初始化的，则需要1.析构函数delete 2.拷贝构造函数 3.=重载开辟内存
	//为什么c++类比较常用，因为类整合了数据表示(数据结构)和实现(算法)，形成了一个比较完整的体系
public:
	String();//默认构造函数
	String(const string& st);//默认带参构造函数
	String(const String& origin);//拷贝构造函数
	String& operator=(const String& st);//重载=深度复制
	~String();
	String operator+(const String& b)const;
	friend ostream& operator<<(ostream& os, const String& st);//因为ostream是外部类，为了让os能够访问到String类内部的成员，需要声明友元函数

};
void call(const String temp);
