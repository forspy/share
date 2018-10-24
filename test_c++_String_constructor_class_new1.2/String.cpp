#include "String.h"

int String::num = 0;//注意，如果类中有静态成员变量要赋初值
					//如果在构造函数中使用new来初始化成员指针
String::String()//默认构造函数
{
	num++;
	len = 0;
	str = new string[len + 1];
	*str = "";
}
String::String(const string& st)//默认带参构造函数
{
	num++;//更新静态
	len = st.size();//与st.length()一致
	str = new string[len + 1];
	*str = st;
}
//深度复制对象类型要一致
//隐式的传参需要拷贝构造
String::String(const String& origin)//拷贝构造函数 另外返回对象将调用拷贝构造函数？？返回引用不会
{
	this->len = origin.len;
	this->str = new string[len + 1];
	*(this->str) = *(origin.str);
	num++;//要写的，因为在子函数代码段结束时会调用析构函数num--
}
String String::operator+(const String& b)const
{
	return String(*str + *(b.str)); //另外返回对象将调用拷贝构造函数,return将隐式的创建一个临时对象，创建的过程调用拷贝构造函数，子函数中的对象将调用析构函数销毁
									//返回引用不会调用构造和析构函数，如果要返回一个局部对象，则应该返回对象而不是引用
}
String& String::operator=(const String& a)//显示的对象=对象  注意了：一般引用参数对象是const类型，返回也要是const类型（对应），除了：operator函数
{
	if (this == &a)
		return *this;
	delete[] this->str;
	this->len = a.len;
	this->str = new string[len + 1];
	*str = *(a.str);//string对象=string对象才能把值拷过来
	return *this;
}
//析构函数
String::~String()
{
	num--;
	delete[] this->str;
}
//为了实现输出需要重载<<
ostream& operator<<(ostream& os, const String& st)
{
	cout << *(st.str);
	return os;//return os是为了连续输出(cout<<A)<<B<<endl;另外ostream和istream是没有public拷贝构造函数的，因此必须返回引用
}


void call(const String temp)//使用拷贝构造
{
	cout << temp << endl;
}