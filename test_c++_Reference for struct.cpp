#include<iostream>
#include<string>
using namespace std;
struct test& ref_func(struct test& a, const struct test& b);

struct test
{
	string name;
	int value;
};
int main()
{
	struct test one = { "first",1 };
	struct test two = { "second",2 };
	cout << ref_func(one, two).value << endl;//ref_func返回一个引用，相当于使用one
	cout << one.value << endl;
	one = { "first",1 };
	cout << ref_func(ref_func(one, two), two).value << endl;//将返回来的引用值作为参数继续传入
	cout << one.value << endl;//上述改变了one两次
	ref_func(one, two).name = "return & ref_value is a left_value!";//注意：左值（例如变量，返回的引用）表示一个可修改的内存块，右值（常规返回类型,在临时内存单元）不能通过地址访问的值
	cout << one.name << endl;
}

struct test& ref_func(struct test& a, const struct test& b)
{
	a.value = a.value+b.value;
	return a;//返回的其实是one（a），如果变成struct test ref_func，返回的是one（a）的拷贝（拷贝增加了内存和运行时间）
}