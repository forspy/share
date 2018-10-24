#include<iostream>
#include<new>//定位new运算符头文件，让new指定要使用的位置
#include<string>
using namespace std;
struct test
{
	char name[20];
	int num;
};
char buffer1[50];
char buffer2[100];
//测试类
class Test
{
private:
	string words;
public:
	Test(const string& s="testing")
	{
		words = s;
		cout << words << " constructed" << endl;
	}
	~Test()
	{
		cout << words << " destroyed" << endl;
	}
	void show() { cout << words << endl; }
};
int main()
{
	//new初始化
	int* pi = new int(6);//给*pi设值6
	/*int* p = new int[6,1];
	std::cout << p[5] << std::endl;*/
	struct where
	{
		double x;
		double y;
	};
	where* one = new where{1.0, 2.0};
	int* ar = new int[4]{ 1,2,3,4 };
	delete one;
	delete[] ar;
	//--------定位运算符
	test* p1 = new (buffer1) test;//在全局数组中buffer1中分配内存给结构test
	int* p2 = new(buffer2) int[20];//在全局数组中buffer2中分配内存给20个int类型
	std::cout << (void*)buffer2 << std::endl;//因为p2的类型与buffer2的类型不同，如果不转换将输出字符串，所以需要对buffer2做(void*)类型的转换
	//这样得到buffer2的地址，而buffer2里面存的是int类型，所以cout会输出int类型的值
	//不能用delete或delete[]释放，因为定位new开辟在静态区

	//---------类定位new测试
	cout << "--------" << endl;
	char* buffer = new char[512];
	Test *pc1, *pc2;
	pc1 = new (buffer)Test;
	pc2 = new Test("hello");
	cout << "buffer address:" << (void*)buffer << endl;
	cout << "pc1 address:" << pc1;
	pc1->show();
	cout << "pc2 address:" << pc2;
	pc2->show();
	//修改new定位位置
	Test* pc3 = new (buffer + sizeof(Test)) Test("hello world!!");
	cout << "pc3 address:" << pc3;
	pc3->show();
	delete pc2;
	//因为是定位new的所以系统不会自动析构，需要显式手动析构
	//1.手动析构需要注意析构顺序，晚创建的对象可能依赖早创建的对象，所以是后进先出的析构方式和栈一样
	//2.当所有对象都被析构以后，才能释放用于储存这些对象的缓存区
	pc3->~Test();//调用函数都要加括号
	pc1->~Test();
	//定位new因为是定位在buffer上，所以不需要通过pc1和pc3释放
	delete[] buffer;//直接释放buffer即可
}