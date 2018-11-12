#include<iostream>
using namespace std;
class A
{
public:
	int m_a{ 10 };//类内初始化
	A(const A& other){ }//写了构造就没有默认无参构造了
	A() = default;//还原默认
	//A(const A& other) = delete; 与放到private一样
};
class B
{
private:
	int m_a, m_b, m_c;
public:
	B(int a, int b, int c):m_a(a),m_b(b),m_c(c){ }
	B():B(10,20,30){ }//无参委托三参构造
	void show() { cout << m_a << m_b << m_c << endl; }

};
int main()
{
	//新增 long
	cout << sizeof(int) << endl;//x86 4位  x64 8位看debug左边可以调，所以一般跨平台用long
	cout << sizeof (long long) << endl;
	int* p = nullptr;//内部还是0，逻辑上是空  null是0指针
	cout << p << endl;
	using dtype = int;//类型取别名，适用于长类型名
	dtype dt = 20;
	cout << typeid(dt).name() << endl;
	//单值自动识别类型
	auto ai = 10;

	A a;
	cout << a.m_a << endl;
	int arr[5] = { 1,2,3,4,5 };
	int arr1[]{ 1,2,3,4,5 };//构造式赋值
	//范围for循环
	for (auto i : arr)
	{
		cout << i << endl;
	}
	//右值引用
	int num = 10;
	int& l_num = num;//左值引用
	int&& r_num = 10;//右值引用
	//移动语义（移动操作）移动完了以后右值没了

	//lambda表达式(匿名函数)
	auto sum = [](int a, int b) {return a + b; };
	//智能指针式一个类:唯一指针,共享指针，自动释放unique_ptr shared_ptr
	//final 写右边
	//类被final修饰不能被继承
	//virtual函数被final修饰不能被重写 

}