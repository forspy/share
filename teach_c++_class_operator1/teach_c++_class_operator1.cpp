#include"class_operator1.h"

int main()
{
	Complex cp1(1, 2);
	cp1.print();
	Complex cp2(2, 4);
	cp2.print();
	Complex cp3 = cp1 + cp2;
	cp3.print();
	Complex cp4 = cp1 + cp2 + cp3;
	cp4.print();
	Complex cp5 = cp1 - cp2;
	cp5.print();
	cout << "------" << endl;
	cout << cp1++ << endl;
	cout << cp1 << endl;
}