#include"Mystring.h"

int main()
{
	char* p = "test";
	Mystring A;
	A = p;//这一步调用带参构造函数
	cout << A << endl;
	Mystring B("hello");
	Mystring C(" world!!!");
	Mystring D = B + C;
	cout << B<<"+"<<C<<"="<<D << endl;

	cout << B << "+=" << C << "为";
	B += C;
	cout << B << endl;
	Mystring E;
	cin >> E;
	cout <<"输入结果为："<< E << endl;
	int i = 1;
	cout << "第"<<i<<"个字符是"<<E[i] << endl;
	cout << E << "的长度为" << E.length() << endl;
}