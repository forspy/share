#include"Integer.h"
#include<iostream>
using namespace std;
int main()
{
	Integer i1(10), i2(20);
	//普通指针：通常取地址做法-----
	int* p1 = &i1.m_i;
	int* p2 = &i2.m_i;
	cout << p1 << endl;
	cout << p2 << endl;
	//----------------
	//成员指针 表示的是该成员指针相对于这个对象的偏移值
	//从近到远，从右到左，括号优先
	int Integer::* p = &Integer::m_i; //(int Integer::)是Integer里面的int类型的东西2.要保持类型一致，访问到的其实是偏移值
	//*p其实代表的是成员
	cout << "对P直接输出" << endl;
	//cout << p << endl;//
	//通过.*给成员指针指向的成员赋值（如果i1是一个对象指针则为->*）
	i1.*p = 50;
	A a;
	int A::* pa = NULL;
	//目标是输出pa指针的值，即地址
	cout << pa << endl;//直接这样会显示0？为什么？
	cout << "------" << endl;
	cout << *(int*)&pa << endl;//(int*)&pa是把int A::类型的指针pa的地址强制转化成(int*)类型，*(int*)&pa然后解引用得到pa的值，即NULL的相对地址（偏移量）
	pa = &A::m_a;
	cout << *(int*)&pa << endl;
	pa = &A::m_b;
	cout << *(int*)&pa << endl;
	//以上结果显示了指针的相对对象偏移，所以叫成员指针
	//强转不会对变量有影响，相当于编译器把一个变量类型解释成另一个变量类型
	//volatile
}