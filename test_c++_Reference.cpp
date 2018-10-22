#include<iostream>
using namespace std;
void swap(int* a, int* b);
void swap1(int& a, int& b);
double ref_cub(const double &ra);//这样的函数原型将禁止引用修改实参的值
int main()
{
	int rat = 1;
	int& ref_rat = rat;//定义一个int& 类型的引用变量ref_rat,它的地址和rat一样，操作引用变量等价于操作原变量,一个变量两个名称
	//必须在定义引用时将其初始化（区别于指针）,引用很忠心一样确定引用对象便不会改变指向的地址
	//引用等价于 int* const ptr=rat;  ref_rat与*ptr差不多
	//引用不能为空，指针可以为空
	//引用比如char& a 不能接住"hellworld"这种 const char* 类型的（非常量限定） 指针char* p可以接住"hello world" 
	cout << rat << endl << ref_rat << endl << "&rat=" << &rat << endl << "&ref_rat=" << &ref_rat << endl;
	int bus = 2;
	ref_rat = bus;
	cout << "&ref_rat=" << &ref_rat << endl << "&bus=" << &bus << endl << "rat=" << rat << endl;//对引用变量赋值其他变量并不会改变该引用变量指向的地址,但会改变原引用对象的值

	int u;
	int v;
	u = 3;
	v = 4;
	swap(u, v);
	cout << u << v << endl;
	u = 3;
	v = 4;
	swap1(u, v);
	cout << u << v << endl;
}

void swap(int* a, int* b)//通过指针交换
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap1(int& a, int& b)//通过引用交换,一个变量两个名称,按引用传递，使用实参初始化形参，符合规则
//引用一般需要输入变量或指针，如果实参输入数据（右值）如 1，将形成临时变量（局部变量）c++11可以使用int&& a=1;双&&的右值引用
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

