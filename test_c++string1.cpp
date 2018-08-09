#include<iostream>
#include<string>//make string class available,使用c++标准库中的string类
using namespace std;
const int SIZE = 20;
int main()
{
	char name[SIZE], name1[SIZE], name2[SIZE], name3[SIZE];
	string str1;//声明创建一个长度为0的string对象,str1是一个对象
	cout << "please enter a string!" << endl;
	cin >> str1;
	string str2 = "hello!";//string类可以不声明数组的长度
	cout << str1 << str2 [0]<< endl;
	string str3;
	str3 = str1 + str2;//string简化了字符串的合并操作
	cout << str3 << endl;
	cout << "please enter your name" << endl;
	cin >> name;//cin当遇到空格时会判断一次输入结束
	cout << "please enter your name again!" << endl;
	cin >> name1;
	cout << name<<name1 << endl;
	cin.get();//为什么要加这一句，因为cin读取字符串的时候，将回车键生成的换行符留在了输入队列之中。
	//后面的cin.getline()看到换行符后，将认为这是一个空行，并将空字符赋值给下一个数组。
	//可以利用cin.get()来接住这个回车符。
	cout << "test 2！" << endl;
	cout << "please enter your name" << endl;
	cin.getline(name2, 20);//在调用面向行的输入时前面不能有
	cout << "please enter your name again!" << endl;
	cin.getline(name3, 20);
	cout << name2 << name3 << endl;
	return 0;
}