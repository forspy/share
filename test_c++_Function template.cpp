//对于不同类型使用同一种算法时，可以使用函数模板
//函数模板的使用方式，如：template<typename T>
//1.关键字template和typename是必须的
//2.必须使用尖括号
//3.类型名可以任意选择
//4.不用在结尾加;
//5.在函数原型和具体函数处都要定义一次
//6.模板也可以只替换函数中的部分参数
#include<iostream>
template<typename T>//template<calss T> 也行
void my_swap(T& a, T& b);
using namespace std;
template<typename T>
void my_swap(T& a, T& b, T& c);//三个数的交换完成 重载模板对于相同的T传入的类型要相同


struct job
{
	char name[20];
	double salary;
};
//调用时的优先级为1.非模板函数2.具体化原型3.普通模板函数
//具体化原型,编译器将my_swap()生成一个使用job类型的实例
template <> void my_swap<job>(job& j1, job& j2);
int main()
{
	int i = 1;
	int j = 2;
	my_swap(i, j);
	//swap(i, j);//c++中写好了swap
	cout << "i=" << i << endl << "j=" << j << endl;
	double m = 2.33;
	double n = 3.14;
	my_swap(m, n);
	cout << "m=" << m << endl << "n=" << n << endl;
	int o = 111;
	int p = 222;
	int q = 333;
	my_swap(o, p, q);
	cout << "o=" << o << endl << "p=" << p << endl << "q=" << q << endl;
	job A = { "xiaoming",5000 };
	job B = { "xiaowang",15000 };
	my_swap(A, B);
	cout << "xiaoming =" << A.salary << endl << "xiaowang =" << B.salary << endl;
}
template<typename T>//template<calss T> 也行
void my_swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<typename T>
void my_swap(T& a, T& b, T& c)//三个数的交换完成重载模板
{
	T temp;
	temp = a;
	a = b;
	b = c;
	c = temp;
}

//具体化原型
template <> void my_swap<job>(job& j1, job& j2)
{
	double temp;
	temp = j1.salary;
	j1.salary = j2.salary;
	j2.salary = temp;
}