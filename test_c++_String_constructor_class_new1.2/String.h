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
