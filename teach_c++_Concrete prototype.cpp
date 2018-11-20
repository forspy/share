#include<iostream>
using namespace std;

//完全具体化原型

template<typename T>
T max(T a, T b)
{
	cout << typeid(T).name() << endl;
	return a > b ? a : b;
}
//完全具体化原型
template<>
const char* max(const char* a, const char* b)
{
	return strcmp(a, b) >0 ? a : b;//这里具体化的作用就体现出来了
}

template<typename T>
class Stack
{

};
//完全具体化
template<>
class Stack<bool>
{

};
//部分具体化
//template<typename T,typename Allocator>//内存构造器
//class vector<bool, Allocator>//只指出bool
//{
//
//};
//类模板的部分具体化和完全具体化更像是对类的重载
//匹配的时候优先匹配指针类型的，然后是具体到泛型
template<typename T, typename A>
class Test
{
public:
	Test() { cout << "泛型" << endl; }
	T a;
	A b;
};
//例如：部分具体化
template<typename A>
class Test<int,A>
{
public:
	Test() { cout << "部分具体化" << endl; }
	int a;
	A b;
};
//例如：完全具体化
template<>
class Test<int, int>
{
public:
	Test() { cout << "完全具体化" << endl; }
	int a;
	int b;
};
int main()
{
	cout << max(5, 10) << endl;
	cout << max("hello", "world") << endl;
	//这样调用的是泛型函数 return a > b ? a : b;而这样比较的是地址高位 到低位，所以输出hello
	/*增加：
	template<>
	const char* max(const char* a, const char* b)
	{
	return strcmp(a, b) >0 ? a : b;
	}
	之后cout << max("hello", "world") << endl;会输出world，因为strcmp
	*/
	Test<int,double> ss1;
	Test<double, double> ss2;
	Test<int, int> ss3;
	//类模板的部分具体化和完全具体化更像是对类的重载,以及具体化可以实现类内的不同功能
}