#include<iostream>
#include<cstring>
#include<cstdlib>

#include"human.h"
using namespace std;
human::human()
{
	head = 1;
	body = 2;
	hand = 3;
	foot = 4;
}

void human::walk(int head,int b,int c,int d)//注意不要让实现中的形参名同类成员名相同
{
	//头
	this->head = head;//重要：可以使用this来区别局部变量和类成员变量，显示写出，this划出了一个ecx寄存器来来保存当前对象的地址
	//身体
	body = b;
	//手
	hand=c;
	//脚
	foot=d;
}
void human::show()
{
	//头
	cout << head << endl;
	//身体
	cout << body << endl;
	//手
	cout << hand << endl;
	//脚
	cout << this->foot << endl;//实质上存在一个this指针指向当前对象
}