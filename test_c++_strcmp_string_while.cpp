#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char word[5] = "?ate";
	for (char a = 'a'; strcmp(word, "mate"); a++)//非0就为ture  0就为false
	{
		word[0] = a;
		cout << word<< endl;
	}
	cout << "使用string类后重载了（重新定义了）关系运算符\n";
	string name = "?ate";
	for (char b = 'a'; name != "mate"; b++)
	{
		name[0] = b;
		cout << name << endl;
	}
}