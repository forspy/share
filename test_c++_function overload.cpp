//当没有往函数中添加参数时，如果想让函数使用默认值，则必须在函数原型中给参数赋默认值（对于同一类型的参数）
//通过使用默认参数，可以减少要定义的析构函数、方法以及方法重载的数量
//-----------------
//函数重载(对于不同类型的参数)
//1.函数重载的关键是函数的参数列表--函数的特征标
//2.如果参数数目或参数类型不同，则特征标不同
//3.类型和类型引用视为一个特征标，如：int x和int& x
//4.特征标不区分const和非const变量
//5.返回类型不同，但特征标相同不能作为函数重载
#include<iostream>
const int SIZE = 80;
using namespace std;
char* left(const char* str, int n = 1);//n为要截取的字符数,默认n=1为截取左边第一个字符
unsigned long left(unsigned long num, int n);
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
	unsigned long value = 123456789;
	cout << "enter cut size" << endl;
	int number;
	cin >> number;
	cout << left(value, number) << endl;
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

unsigned long left(unsigned long num, int n)
{
	int digits = 1;
	if (num == 0 || n == 0)
		return 0;
	unsigned long temp = num;
	while (temp /= 10)
		digits++;//判断传入的数一共有几位
	if (digits > n)
		for (int i = 0; i < digits - n; i++)
			num /= 10;
	return num;
}
