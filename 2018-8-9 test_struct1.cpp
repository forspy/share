#include<iostream>

using namespace std;
struct inflatable//结构
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	inflatable guest =
	{
		"Glorious Gloria",
		1.88f,//浮点型表示方法在数字后面加f
		29.99
	};
	//guest={"Glorious Gloria",1.88f,29.99};
	//cout << sizeof inflatable << endl;测试这个结构体的大小
	cout << guest.name << guest.volume << endl;
	inflatable others;
	others = guest;//c++结构体到结构体的赋值
	cout << others.name << endl;
	enum hi{one,two,three};//枚举  为0，1，2
	cout << one<< endl;
	union oneof//联合
	{
		int i;
		double j;
	};
	oneof test;
	test.i = 1;
	//test.j = 1.0;
	cout << test.i;//只有一个是当前的成员，如果两个都被赋值则取后一个
}

