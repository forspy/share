//support.cpp ---- use external varibales . compile with external.cpp
#include <iostream>
using std::cout;
extern double warming; //use warming another file
void update(double dt);
void local();

void update(double dt) {
	extern double warming; //extern 使用全局文件共享的变量warming
	warming += dt;
	cout << "Updataing global warming to " << warming << "degress.\n";
}

void local() {
	//定义一个局部的自动变量warming，在函数内屏蔽全局文件共享的warming
	double warming = 0.8;
	cout << "Local warming = " << warming << "degress.\n";
	cout << "But global warming = " << ::warming << "degress.\n";
	//使用C++作用域解析符访问全局共享的warming，而不是函数内定义的自动变量warming。
}