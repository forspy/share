#include<iostream>
#include<string>
using namespace std;
template<typename T>

class Parent
{
private:
	T m_data;
public:
	Parent(T data=0) { m_data = data; }//前提是T类型需要注意=重载的深拷贝
};
//如果派生类不是模板类，则必须显示指出基类的类型,必须要用构造函数列表来显示指出基类模板类型构造函数初始化
class ChildOne :public Parent<int>
{
private:
	int m_clone;
public:
	ChildOne(int a=0, int b=0) :Parent(b)
	{
		m_clone = a;
	}
};
//如果派生类也是模板类，要么显式指明基类的类型，要么使用泛型指明
template<typename T>
class ChileTwo :public Parent<T>
{
private:
	int m_clone;
public:
	ChileTwo(int a = 0, T b = " ") :Parent(b)
	{
		m_clone = a; 
	}
};
int main() 
{
	ChildOne one;
	ChileTwo<string> two;//模板是二次编译
	cout << sizeof(one) << " " << sizeof(two) << endl;

}