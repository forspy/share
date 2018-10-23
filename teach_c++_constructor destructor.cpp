/*
QQ1-操作系统--底层硬件（tcp/ip）--底层硬件--操作系统--QQ2
分布式应用--ACE库
数字图像处理--openCV

计算机行业T型发展，先纵深再横向扩展T
endl清缓存
const char* p="hello";
名称空间别名namespace abc=a:b:c
联合体内的变量共用一块内存
c++类型检查更严格
*/
/*
面向对象三大特性：封装、继承、多态
*/
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
	void show();
};

//初始化表
test::test()
{

}
test::test(int a):num(a)
{
	cout << "初始化表方式构造"<<num << endl;
}
void test::show()
{

}
int main()
{
	test k{ 1 };//不推荐使用
	test* pa = new test[7];//堆区new对象
	cout << *((int*)pa - 1) << endl;
	delete[] pa;
	test a[4];//创建一个4个对象的数组
	test* p = a;//创建一个指向对象数组的指针
	a[1].show();
	(p + 1)->show();
	1[a].show();//x[y]=*(x+y)=*(y+x)=y[x];
}