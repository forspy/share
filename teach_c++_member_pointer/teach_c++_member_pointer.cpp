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
	cout << *(int*)&p << endl;//偏移值其实和对象无关，任何对象的该成员都是这个偏移值
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
	cout << *(int*)&pa << endl;//(int*)&pa是把int A::类型的指针pa的地址强制转化成(int*)类型，*(int*)&pa然后解引用得到pa指向的地址，即NULL的相对地址（偏移量）
	pa = &A::m_a;
	cout << *(int*)&pa << endl;
	pa = &A::m_b;
	cout << *(int*)&pa << endl;
	cout << pa << endl;//直接输出会出现（0/1）0表示没有偏移，1表示有偏移但是不会给出偏移量，需要强转
	//以上结果显示了指针的相对对象偏移，所以叫成员指针
	//强转不会对变量有影响，相当于编译器把一个变量类型解释成另一个变量类型

	A aa = 10;
	//B bb = 10;//这样的隐式转换就不允许
	B bb1(10);
	//或者 后两种其实都是强制类型转换后再赋值，所以写成显式的效率高
	B bb2 = (B)10;
	B bb3 = B(10);
	cout << bb1.show() << bb2.show() << bb3.show() << endl;

	//C++类型转换
	double num = 0.03;
	cout << (int)num << endl;//c风格强制类型转换，不会改变num内存，只会改变输出，编译器把num暂时解释为int类型
	//当然也可以把int看成一个类
	cout << int(num) << endl;

	//const_cast专门用来去常const
	int i = 49;
	const int* pc1 = &i;//这里的const表示不能修改i的值
	//int* p1 = pc1;//这样是不行的，因为如果可以那么*pc1就可以去修改i，而const int* pc1=&i;表明i是不能被修改的，形成冲突
	//所以得出了const int*类型不能用来初始化int*类型，即c++里面强调的类型一致
	//解决方法
	//1.c风格去常
	 p1 = (int*)pc1;
	char* str = (char*)"hello world";//注意再vs2017里面会报错
	//2.使用c++里面的去常const_cast
	str = const_cast<char*>("hello world");//去常

	//有趣的情况
	const int  rmb = 100;
	const int* ppp = &rmb;
	int* qqq = const_cast<int*> (ppp);
	*qqq = 200;
	cout << *qqq << *ppp << rmb << endl;//200 200 100
	cout << qqq << ppp << &rmb << endl;//地址都一样
	//机制：寄存器来读取内存，再读寄存器 所以100是真正的常量 rmb是栈区普通变量只是声明这个变量不能修改
	//寄存器看到rmb前面的const就不会去读里面的内存（不会内存确认），直接读100
	volatile const int m_rmb = 100;
	volatile const int* m_ppp = &m_rmb;
	int* m_qqq = const_cast<int*> (m_ppp);
	*m_qqq = 200;
	cout << *m_qqq << *m_ppp << m_rmb << endl;//200 200 100
	cout << (int*)m_qqq << (int*)m_ppp << (int*)&m_rmb << endl;//地址都一样 //“volatile const int *”: 将值强制为布尔值“true”或“false”(性能警告),与面一样的处理,所以(int*)强转一下
	//单片机 嵌入式里面常用到volatile 跟寄存器打交道 要让寄存器和内存里面的值一致
	//mutalbe也是可变的，以后讲
}