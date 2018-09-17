//当没有往函数中添加参数时，如果想让函数使用默认值，则必须在函数原型中给参数赋默认值
//通过使用默认参数，可以减少要定义的析构函数、方法以及方法重载的数量
#include<iostream>
const int SIZE = 80;
using namespace std;
char* left(const char* str, int n = 1);//n为要截取的字符数,默认n=1为截取左边第一个字符
int main()
{
	char name[SIZE];
	cout << "enter a string" << endl;
	cin.getline(name, SIZE);
	char* ps = left(name, 4);
	cout << ps << endl;
	delete[] ps;
	ps = left(name);
	cout << ps << endl;
	delete[] ps;
}

char* left(const char* str, int n)//n为要截取的字符数
{
	if (n < 0)
		n = 0;
	//也可以先测测长度
	//int len=strlen(str) 返回有效长度,需要#include<cstring>
	//n=(n<len)?n:len;
	//char* p=new char[n+1];
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n&&str[i]; i++)
	{
		p[i] = str[i];//复制字符串到堆上
	}
	p[i] = '\0';
	return p;
}