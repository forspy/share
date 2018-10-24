/*
在构造函数中使用new时应注意的事项
1.如果在构造函数中使用new来初始化成员指针，则应在析构函数中使用delete
2.new和delete必须相互兼容。new对应delete,new[]对应delete[]。
3.如果有多个构造函数，则必须以相同的方式使用new，要么都带[]，要么都不带（建议一个的化new[1],因为析构函数只有一个）
深度复制构造应该更新所有受影响的静态类成员
*/
#include"String.h"

int main()
{
	String A("hello world");
	cout << A << endl;
	String B = "SS";//使用了带参构造法
	cout << "B="<<B << endl;
	A = B;//使用=重载
	call(A);
	String C = "!!";
	cout << A + C << endl;
	String* p = new String(A);//new的初始化方式1
	cout << *p << endl;
	delete p;
	String* ptr = new String("hello world!!");//new的初始化方式二
	cout << *ptr << endl;
	delete ptr;
}

