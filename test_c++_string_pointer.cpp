#include<iostream>
#include<string>
using namespace std;
void show(string* p);
int main()
{
	string name = "hello";
	show(&name);//对象传地址可以
}

void show(string* p)
{
	cout << *p << endl;//cout类对象的话需要对象实体
}