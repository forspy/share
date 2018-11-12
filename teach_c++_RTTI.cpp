#include<iostream>
using namespace std;
class A
{
public:
	virtual void foo()
	{
		cout << "A::foo（）" << endl;
	}
};

class B :public A
{
public:
	void foo()
	{
		cout << "B::foo()" << endl;
	}
};

int main()
{
	//const_cast;
	//reinterpret_cast;
	//static_cast<目标类型>(原类型变量),1.所有隐式类型转换都可以用
	//2.隐士类型转换的逆转换
	double adouble = 11.11;
	void* pv = &adouble;
	//void* pv1 = static_cast<void*>(&adouble);
	double* pv2 = static_cast<double*>(pv);
	A a;
	B b;
	A* pa = &b;//上行转换时安全的，有隐式类型转换 安全
	cout << typeid(pa).name()/*class A*/ << endl;//typeid时看运行时类型的typeid(pa)==typeid(pb)类型不一样会抛出异常-----
	B* pb = static_cast<B*>(&a);//不安全，下行转换,没有RTTI
	cout << typeid(pb).name()/*class B*/ <<pb<< endl;
	B* pb1 = dynamic_cast<B*>(&a);//动态类型识别 安全
	cout << typeid(pb1).name()/*class B*/ << pb1 << endl;//对于指针不一致抛出NULL 对于引用抛出bad_typeid异常
	B* pb2 = dynamic_cast<B*>(pa);
	cout << typeid(pb2).name()/*class B*/ << pb2 << endl;
	//static_cast编译时转换 dynamic_cast在运行时运行//静态逆转换只是强制的转过去，但是实际访问没有的区域的时候就会报错，动态逆转换运行就给你设成NULL或bad_typeid异常
}