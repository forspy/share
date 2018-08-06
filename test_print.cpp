#include<iostream>//输入输出头文件
#include<cmath>
void simon(double);//声明一个函数原型
int stonetolb(int);
using namespace std;//1.make definitions visible 使用count和endl的前提，使得程序可以使用std名称空间中的定义
//2.可以申明在函数外，这样下面的函数不需要再次声明

int main()//main的值返回给操作系统
{
	
	//2.using 编译指令 意味着其实是使用了名称空间（namespace）

	cout << "Come up and C++ me some time.";//1.cont全称是std:count，是在调用了没有扩展名.h的头文件后的用法
	//2.是c++新的头文件，区别于c
	//3.如果去掉编译指令using也可以用std::count到达相同的效果
	//4.cout是一个预定义的对象
	//5.<<为插入运算符
	//6.<<(插入运算符)与<<(左移运算符)相同，是一个运算符重载的例子
		cout << endl;//start a new line，endl移到下一行
	cout << "you won't regret it!" << endl;
	int carrots;//decalare an integer variable
	carrots = 25;
	cout << carrots;
	cout << endl;
	carrots = carrots - 1;
	cout << "Now I have " << carrots << " carrots." << endl;
	cin >> carrots;//c++ input
	cout << "Now I have " << carrots << " carrots." << endl;
	//类是C++中面向对象编程（OOP）的核心概念之一。
	//iostream是一个类
	//cout是ostream中的一个类对象，cin是istream中的一个类对象。（ostream和istream都是iostream头文件中的成员）
	//c++之所以有吸引力，是因为存在大量支持UNIX，Macintosh，Windows编程的类库
	double area;
	cin >> area;
	double side=sqrt(area);//初始化
	cout << "平方后的值为" << side << endl;
	double answer = pow(2, 3);//pow是幂函数，这里表示2^3;
	cout << answer<<endl;
	double coins;
	cin >> coins;
	simon(coins);
	
	int stone;
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " stone=";
	cout << pounds << " pounds"<<endl;
    return 0;
}

void simon(double n)
{
	//using namespace std;//
	cout << "Now have "<<n << " coins!"<<endl;
}

int stonetolb(int sts)
{
	int pounds = 14 * sts;
	return pounds;
}