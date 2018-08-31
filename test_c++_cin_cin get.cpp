#include<iostream>
using namespace std;
int main()
{
	char name[20];
	cin.getline(name,20);
	char str[20];
	char s;
	cin.get(str, 3).get(s).get();//c++支持函数重载，对于可以输入的多个参数，可以只输入部分参数
	//编译器会去寻找有不同参数的get()版本
	//cin >> name;
	cout << name << endl;
	cout << str << endl;
	//CTRL+Z 和enter=EOF
}