#include"Mystring.h"

int main()
{
	Mystring A;
	Mystring B("hello");
	Mystring C(" world!!!");
	Mystring D = B + C;
	cout << D << endl;
	B += C;
	cout << B << endl;
}