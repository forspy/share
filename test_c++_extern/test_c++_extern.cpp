//external.cpp  --- external variables , compile with support.cpp
#include <iostream>
using namespace std;
double warming = 0.3; // warming defined .
void update(double dt);
void local();
//第一个const防止字符串被修改，第二个const确保数组中每个指针始终指向它最初指向的字符串。
const char * const months[12] =
{
	"January","February","March","April","May",
	"June","July","August","September","October",
	"November","December"
};
int main(int argc, char** argv) {  //使用全局变量
	cout << "Global warming is " << warming << "degress.\n";
	update(0.1);                 //call function to change warming
	cout << "Global warming is " << warming << "degress.\n";
	local();                     //call function with local warming
	cout << "Global warming is " << warming << "degress.\n";
	return 0;
}