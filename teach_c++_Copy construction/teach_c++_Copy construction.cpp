#include"complex.h"

int main()
{
	Complex cp1(1.2);//显示调用
	cp1.print();
	Complex cp2 = 1.2;
	//Complex cp2 = Complex(1.2);//隐式调用  complex cp2=complex(1.2)  这个过程不存在析构
	cp2.print();

	Complex cp3 = cp1;//隐式拷贝
	cp3.print();
	Complex cp4(cp1);//显式拷贝
	cp4.print();

	//new拷贝构造
	Complex* cp5 = new Complex(cp1);

	ninjia* kakaxi = new ninjia(20);
	kakaxi->show();
	ninjia* n1 = new ninjia(*kakaxi);
	n1->show();
	
	delete kakaxi;
	delete n1;//如果是编译器提供的默认拷贝构造函数则不会进行深度拷贝，所以需要深拷贝
	//为成员函数函数回新开辟内存，静态成员也可能需要使用拷贝构造在=，实参赋给形参，return时都会调用拷贝构造
}