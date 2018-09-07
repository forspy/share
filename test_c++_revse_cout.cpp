#include<iostream>
#include<string>
using namespace std;
int main()
{
	string word;
	cout << "请输入一个单词" << endl;
	cin >> word;
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << endl;//
	int a = 20;
	int b = 20;
	cout << a++ <<endl<< ++b << endl;//前置++和后置++运行时间不一样，如果相同效果下对于类而言前缀的效率要比后缀高，后缀的优先级比前缀要高
	//*++p,先++后*
	//++*p，先*后++
	//*p++，先得到*p，然后对p++
	int x = 20;
	{
		int x = 5;
		cout << x << endl;//{ }内使用新变量，不算重{定义
	}
	cout << x << endl;//{ }外使用旧变量
	//也可以利用数组的方法反转字符串
	char temp;
	
	//int i=0;
	for (int j=0, i = word.size() - 1; j < i; j++, i--)//int j=0,int i = word.size() - 1  这样错误的使用了，因为是两个表达式，只要用一个int就行了
		//也可以是for(int i=0;i<word.size()/2-1;i++)  word[i]=word[size-i-1]
	{
		temp = word[j];
		word[j] = word[i];
		word[i] = temp;
	}
	cout << "再次反转" << word << endl;
	//,的作用
	int c ;
	c = 17, 18;
	cout << c << endl;
	c = (17, 18);
	cout << c << endl;
}
