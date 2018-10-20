#pragma once
#include<iostream>

class String_easy
{
private:
	char* str;//指向一样就应该能输出一样的内容啊？
	int len;
	static int num_strings;//对象的个数 这里通过static将num_strings声明为静态储存类，
	//静态储存类特点：无论创建了多少个对象，程序都只创建一个静态变量副本 类的所有对象共享一个静态成员
	
public:
	/*
	   构造分为三种：
	        1、默认构造（无参数）
			2、带参构造（有参数）
			3、拷贝构造（参数是类的对象）
	*/
	//何时调用拷贝构造函数？新建一个对象并将其初始化为同类现有对象时，复制构造函数将被调用
	String_easy(const String_easy& other); //拷贝构造，就是把一个other的对象内容拷贝到本身，这里的参数必须是引用，如果不给引用，是值拷贝，会无限循环调用拷贝构造，const表示不会改变引用对象的值
	/*
	以下都将调用拷贝构造函数
	String_easy test(A);//隐式的赋值
	String_easy test=A;//显式地赋值
	String_easy test=String_easy(A);//调用复制构造函数式地赋值
	String_easy* p=new String_easy(A);//在堆上开辟一块内存建立A的拷贝对象，并用指针P指向该内存
	*/
	/*
	1.默认的复制构造函数逐一复制非静态成员，所以num_strings不会被复制（浅复制），因为静态函数属于整个类，所以他们不受影响
	2.如果成员本身就是类对象，则将使用这个类的复制构造函数来复制成员
	*/

	String_easy(const char* s);//构造函数
	String_easy();//默认构造函数
	~String_easy();//析构函数
	String_easy& operator=(const String_easy& st);//由于在=赋值的时候也会遇到深度复制的问题，因此为String_easy类编写赋值运算符
	//友元函数
	friend std::ostream& operator<<(std::ostream& os, const String_easy& st);

};