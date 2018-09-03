#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char name[50];
	double price;
	ofstream outfile;//声明一个ofstream类的对象
	outfile.open("carinfo.txt");//重点：声明了ofstream类的对象后，可以使用该类的函数.open(),输入文件名 2.默认打开方式会清除原来该文本文件中的内容
	//char filename[10];也可以是将字符串作为参数输入到.open（）类函数中
	//outfile.open(filename)
	cout << "enter the name\n";
	cin.getline(name, 50);
	cout << "enter price\n";
	cin >>price;

	cout << fixed;//使用一般方式输出浮点数而不是科学计数法
	cout.precision(2);//小数点后面两位
	cout.setf(ios_base::showpoint);//显示小数点
	cout << name << '\n';
	cout << price << '\n';
	//outfile对象的函数使用方式和cout一样
	outfile << fixed;
	outfile.precision(2);
	//outfile.setf(ios_base::showpoint);
	outfile << name << '\n';
	outfile << price << '\n';

	outfile.close();//关闭文件
	return 0;
}