/*
类有内存对齐 
string 28字节
类大小看变量 函数不占内存
类什么也不写占1字节
若定义了构造函数，则编译器不会提供默认构造函数

*/
#include<iostream>
using namespace std;
class test
{
private:
	int num;
public:
	test();
	test(int a);
};
//初始化表
test::test()
{

}
test::test(int a):num(a)
{
	cout << "初始化表方式构造"<<num << endl;
}

int main()
{
	test k{ 1 };//不推荐使用
	test* pa = new test[7];
	cout << *((int*)pa - 1) << endl;
}