//类继承介绍
//基类->派生类（如：ostream->ofstream）
//   继承       继承可以使派生类使用基类的方法
//继承的另一个特点：基类引用可以接住派生类的对象 如：ostream& a=cout,也可以是ostream& a=fout;
//关于何时使用引用，何时使用指针，何时传递值等介绍
//1.如果数据对象很小，如内置数据类型或小型结构，则按值传递
//2.如果数据对象是数组，则按指针传递（需要修改内置数据类型如fun(&x)，则也使用指针修改）
//3.如果数据对象是较大的结构，则使用指针或引用，以提高程序效率
//4.如果数据对象是类对象，则使用引用，或者使用指针接住对象。
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
const int LIMIT = 2;
void file_it(ostream& os, double fo, const double* fe, int n);
int main()
{
	ofstream fout;
	const char* fn = "data.txt";
	fout.open(fn);
	if (!fout.is_open())//.is_open()判断是否打开
	{
		cout << "can't open" << fn << endl;
		exit(EXIT_FAILURE);
	}
	double objective;//物镜焦距
	cout << "请输入物镜焦距mm" << endl;
	cin >> objective;
	double eps[LIMIT];//不同目镜的焦距
	cout << "请输入目镜焦距mm" << endl;
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "目镜#" << i << "=  ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
}

void file_it(ostream& os, double fo, const double* fe, int n)
{
	//预先储存好格式化方式
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);//使用定点表示法，并将这种表示方式存在initial中，os是ostream的类对象，可以使用该类的方法.setf()
	//------------
	os.precision(0);//不输出小数部分
	os << "物镜焦距为" << fo << "mm" << endl;
	os.setf(ios::showpoint);//显示小数方式
	os.precision(1);//显示一位小数
	os.width(12);//.width()类方法用于显示下一个字段的宽度，用完下一个字段恢复到默认
	os << "目镜焦距";
	os.width(15);
	os << "放大倍数" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];//os是ostream&类引用可以接住cout和fout
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;//放大倍数为物镜焦距处以目镜焦距
	}
	os.setf(initial);//重新设回fixed格式
	
}
