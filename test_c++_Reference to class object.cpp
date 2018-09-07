#include<iostream>
#include<string>
using namespace std;
string version1(const string& a, const string& b);
const string& version2(string& a, const string& b);
string& version3(const string& a, const string& b);
int main()
{
	string input;
	string copy;
	string result;

	cout << "enter a string!" << endl;
	getline(cin, input);
	copy = input;
	result = version1(input, "***");
	cout << "version1:   " << result << endl;
	cout << "original:   " << input << endl;
	input = copy;//reset
	result = version2(input, "###");
	cout << "version2:   " << result << endl;
	cout << "origina2:   " << input << endl;
	input = copy;//reset
	result = version3(input, "@@@");
	cout << "version3:   " << result << endl;
	cout << "origina3:   " << input << endl;
	input = copy;//reset

}

string version1(const string& a, const string& b)//const sting& 能接住string（但const string接不住string,string 能接住const string）
//const string&能接住char* （string 能接住char*），这里const char* 只能使用const string&接住
{
	string temp;
	temp = b + a + b;
	return temp;
}

const string& version2(string& a, const string& b)//have side effect，const string&表示返回一个引用，该返回的引用不能成为左值（不能被修改）
{
	a = b + a + b;
	return a;
}

//bad design
string& version3(const string& a, const string& b)//将引用一个栈中已经释放的内存，error
{
	string temp;
	temp = b + a + b;
	return temp;
}