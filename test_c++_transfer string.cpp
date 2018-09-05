#include<iostream>
#include<string>
using namespace std;
void display(string* str, int n);
int main()
{
	const int Size = 3;
	string name[Size] = { "hello","world","!!!" };//利用string类型定义字符串数组方便
	display(name, Size);//传入name就行，name本身就是一个地址
}

void display(string* str, int n)//string类型和char的使用方式一样
{
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << endl;
	}
}