#include<iostream>
#include<string>
using namespace std;
class A
{
private:
	const int m_a;//需要用初始化列表初始化
	int a;
	int b;
public:
	A();
	A(int data);
};

A::A() :m_a(0)//给默认的一个值就行，如果没传入参数
{

}

A::A(int data) : m_a(data), a(10), b(b)//按顺序
{

}

class student
{
public:
	student(string const& name, int age) :m_name(name), m_age(age) {}
	//void print(/*相当于const student* this */) const { cout << m_name << "," << m_age << endl; }   //因为隐式this参数不一样所以与不const构成重载，函数后const
	void print() { cout << m_name << "," << m_age++ << endl; }
private:
	string m_name;
	mutable int m_age;//mutable可变异，偷偷开一个后门可使得const对象也可以修改
};

int main()
{
	student stu("hello", 12);
	stu.print();//非const对象可以调用两个，优先调用一般，如果没有函数const，则使用一般函数
	stu.print();
	const student stu1("hello", 99);//const对象只能调用函数const
	stu.print();
	int a = 1;
	int const* p = &a;//const以*为界与const int*p 等价，不能改a内容
	int* const pp = &a;//不能修改指向
}