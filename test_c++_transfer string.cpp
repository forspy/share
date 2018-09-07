#include<iostream>
#include<string>
using namespace std;
void display(string* str, int n);
int main()
{
	const int Size = 3;
	char kk[200];
	cin >> kk;
	cout << kk << endl;;
	//cin.clear();的作用只是清除cin的错误状态，并不会清掉缓存
	cin.getline(kk,100);//结论：使用cin.getline接住剩下的字符,相当于清掉缓存
	cout << kk << endl;;
	char str[100];
	cin.getline(str, 100);//cin.getline只能给char类型赋值cin.getline是iostream类的，getline只能给string类型赋值，因为getline本来就是string类的
	string name[Size];//利用string类型定义字符串数组方便
	for (int i = 0; i < Size; i++)
	{
		getline(cin,name[i]);//不能使用cin.getline(name[i],100]为string类对象赋值
	}
	display(name, Size);//传入name就行，name本身就是一个地址
}

void display(string* str, int n)//string类型和char的使用方式一样
{
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << endl;
	}
}