//endl胡释放缓存
//用一个特定类的对象来管理输入输出流
//<ios>派生出<ostream>(cout)和<istream>(cin),<ostream>和<istream>共同派生出<iostream>
//<istream>-><ifstream>（读取文件） <ostream>-><ofstream> , <iostream>-><fstream>
//        -><istringstream>                  -><ostringstream>  字符串string流
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a = 21;
	//1.setf()设置格式
	cout.setf(ios::showbase);
	cout << "dec " << a << endl;//为整数添加一个进制前缀，默认十进制
	cout.unsetf(ios::dec);//取消（十进制）格式
	cout.setf(ios::hex);//采用十六进制
	cout << "hex " << a << endl;
	//一套开关是配套的，不能省略
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);
	cout << "oct" << a << endl;
	cout.unsetf(ios::oct);//关了默认十进制
	cout << a << endl;
	//-------------
	const char* p = "hello";
	//2.成员函数设置格式
	cout.width(10);//指定域宽 大于空格，小于长度无事发生
	cout << p << endl;
	//----用*填充
	cout.width(10);
	cout.fill('*');
	cout << p << endl;
	//科学计数法
	double pi = 22.0 / 7.0;
	cout.setf(ios::scientific);
	cout << pi << endl;
	cout.unsetf(ios::scientific);

	//四个字符 右对齐 用‘0’填充（常用）
	cout << setw(4) << /*left*/right << setfill('0') << 1 << endl;//以流的方式 
	cout << showbase << hex << 21 << endl;//一次以oct输出21
	bool b = false;
	cout << b << endl;
	cout << boolalpha << b << endl;
	cout << b << endl;
	cout << noboolalpha << b << endl;

	//输出重定向
	//cout标准输出对象 （有缓冲区）cerr 标准错误对象（无缓冲区） clog标准错误对象（有缓冲区）
	//如果内存满了则cout失效，因为没有空间分配缓存了，应该使用cerr（无缓存区）
	//cout因为有缓存区，所以输出可以重定向到一个文件中（输入文件）  cerr只能输出到屏幕
	//测试
	cout << "cout" << endl;
	cerr << "cerr" << endl;
	//tips:shift右键，在此处打开命令窗口 cmd 拖进去也行
	//cmd <<重定向文件名 cerr不会重定向
	//编译
	//过程 .obj/.o->.exe/.out

	cout << "a";
	cout << "b" << ends;//'\0'
	cout << "c" << endl;//'\n'+flush
	cout << "d" << flush;//刷新缓冲区

	char c = cin.get();//获取单个字符
	cout << c << endl;

	cout.put(c);//获取单个字符
	//cout << putc << c << endl;
	endl(cout << c);
	char str[200] = { 0 };
	cin >> str;//读到空格之前
	cout << str;//剩下的缓存输出
	//读入字符串
	cin.getline(str, 20);
	cout << str;
	cin.getline(str, 20, '/');//读到/之前
	cout << str << endl;
}