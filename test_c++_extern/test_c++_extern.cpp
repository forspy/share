//external.cpp  --- external variables , compile with support.cpp
#include <iostream>
using namespace std;
double warming = 0.3; // warming defined .
void update(double dt);
void local();
int main(int argc, char** argv) {  //使用全局变量
	cout << "Global warming is " << warming << "degress.\n";
	update(0.1);                 //call function to change warming
	cout << "Global warming is " << warming << "degress.\n";
	local();                     //call function with local warming
	cout << "Global warming is " << warming << "degress.\n";
	return 0;
}