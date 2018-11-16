//虚继承是专门用来解决菱形继承的问题的，因为如果实继承的话两个派生类里面都会有基类部分
//引用不能修改对象，指针可以修改指向，所以引用在多态方面的表现力较弱
//以函数指针的多态性为例
#include<iostream>
#include"test.h"
using namespace std;
int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}
int divi(int x, int y)
{
	return x / y;
}

typedef int(*func)(int, int);

int call_math(int x, int y, func funcName)
{
	return funcName(x, y);
}

class A
{
public:
	A(){ cout << "A构造" << endl; }
	virtual ~A() { cout << "A析构" << endl; }
	virtual void test() { cout << "A:test" << endl; }
};
class B :public A
{
private:
	int* p;
public:
	B() { cout << "B构造" << endl; p = new int[10]; }
	virtual ~B() { cout << "B析构" << endl; delete[] p; }//基类写了virtual，派生类也会默认virtual
	virtual void test() { cout << "B:test" << endl; }
};
//抽象基类 virtual int func（）=0（纯虚函数）抽象方法，只有纯虚函数的类叫做纯虚类（接口类），抽象基类不能实例化对象
//2.继承纯抽象类需要把所有的抽象方法全部实现，如果有一个没实现，那么该派生类成为抽象基类

//另一种方法实现虚函数表函数指针调用
void CallVirtualFunc(void *pthis, int index = 0)
{
	void(*funptr)(void*);//定义一个函数指针，第一个void是返回类型，第二个void*是该函数的参数表类型
	//如果嫌写函数指针麻烦，可以使用typedef定义一个类型： typedef void(*Funptr)(void*); Funptr ptr;这也是一个函数指针
	long vptrAddr;//保存虚函数表地址
	memcpy(&vptrAddr, pthis, 4);//把对象的前4个字节也就是虚指针地址传过去
	memcpy(&funptr, (long*)(vptrAddr)+index, 4);//memcpy的方法是传入对象的地址，这样需要将funptr的地址传入，
	//而funptr是一个指针，所以对应的long*)(vptrAddr)+index也是一个指针，并且是一个二级指针，这样才能完成类型一致
	//1.把long转成long*相当于取了虚函数表指针的地址reinterpret_cast<long*>(vptrAddr)可太骚了
	//2.改变指针的地址可以改变指针的指向int* p; int** walk=p; walk
	(*funptr)(pthis);//funptr(pthis);也可以
}
//通过二级指针修改一级指针
/*
int fun(void)
{
	int *buf;
	int ret;
	ret = mem_init(&buf);
	return ret;
}
int mem_init(int **buf_t)
{
	*buf_t = NULL;
	return 1;
}
*/
int main()
{
	cout << call_math(1, 2, add) << endl;
	//B b;
	A* arr[2] = { 0 };//利用基类指针数组管理派生类
	arr[0] = new A;
	arr[1] = new B;
	arr[0]->test();
	arr[1]->test();
	N n;
	//每一个有虚函数的类存在一个虚函数表，类对象里面存在一个虚指针指向这个虚函数表，表内元素为函数指针，派生类会继承基类的虚函数表
	Base a;//a对象里多了一个_vfptr,_vfptr指向一个虚函数表，表里存着函数指针（二级指针void**），_vfptr[0]是一个函数指针(void*)，*(_vfptr[0])这样其实就是一个函数名了
	Child b;
	Base* p = &b;
	cout << "sizeof N:" << sizeof N << ",m_a偏移值" << offsetof(N, m_a) << ",m_b偏移值" << offsetof(N, m_b) <<endl;//计算成员相对于类的偏移
	cout << "sizeof Base:" << sizeof Base << ",m_a偏移值" << offsetof(Base, m_a) << ",m_b偏移值" << offsetof(Base, m_b) << endl;
	//virtual函数其实代表一个指针，且与成员的排列顺序无关

	//typedef void(*VFUN)();//VFUN成员函数指针类型，void*传当前调用对象的地址,但是如果是这样的话一会儿利用地址调用就不用输入&a对象地址了，有利有弊
	typedef void(*VFUN)(void*);//加void*表示this指针，因为原型没有参数，重要typedef相当于声明了一个原型
	typedef VFUN* VPTR;//指向虚函数表的指针类型，是一个二级指针
	VPTR _vfptr = *(VPTR*)&a;//指向对象的首地址，
	//VFUN* _vfptr = *(VFUN**)&a;//纯二级指针写法
	//也就是说一级指针指向函数名，二级指针指向虚函数表
	cout << _vfptr << "[" << _vfptr[0] << "," << _vfptr[1] << "]" << endl;
	_vfptr[0](&a);
	_vfptr[1](&a);
	VPTR _vfptr1 = *(VPTR*)&b;
	cout << _vfptr1 << "[" << _vfptr1[0] << "," << _vfptr1[1] << "]" << endl;
	_vfptr1[0](&b);
	_vfptr1[1](&b);
	//-----测试
	cout << "----------另一种方法使用函数call" << endl;//原理也是函数指针取到虚数表指针
	CallVirtualFunc(&a, 0);
	CallVirtualFunc(&a, 1);
	CallVirtualFunc(&b, 0);
	CallVirtualFunc(&b, 1);
	int aa = 0;
	int bb = 99;
	int* pp = &aa;
	int* mm = &bb;
	int** walk = &pp;
	walk = &mm;
	//*walk = mm;
	//--测试结果，只修改二级指针并不会修改一级指针的指向，需要*walk才能修改一级指针的指向
	
}
