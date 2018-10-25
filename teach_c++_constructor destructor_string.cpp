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
//tmain是#define
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
#include<string>
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
test::test(int a):num(a)//初始化列表先于构造函数代码执行
{
	cout << "初始化表方式构造"<<num << endl;
}
void test::show()
{

}

//构造和析构的顺序
class A
{
public:
	A() { cout << "A构造" << endl; }
	~A() { cout << "A析构" << endl; }
	/*
	执行析构函数代码
	析构成员变量
	析构基类部分
	释放整个对象占用内存
	*/
};

class B
{
public:
	B() { cout << "B构造" << endl; }
	~B() { cout << "B析构" << endl; }
	A aaa;
};
class C
{
public:
	C() { cout << "C构造" << endl; }//从结果来看，构造成员bbb是要先于构造函数执行的
	~C() { cout << "C析构" << endl; }//从结果来看，先析构析构函数后析构成员
	B bbb;
};
int main()
{
	test k{ 1 };//不推荐使用
	test* pa = new test[7];//堆区new对象
	//new失败了会返回异常exception
	cout << *((int*)pa - 1) << endl;
	delete[] pa;
	test a[4];//创建一个4个对象的数组
	//构造函数的对象创建过程：
	/*
	1.为整个对象分配内存
	2.构造基类部分（如果有点话）
	3.构造成员变量
	4.执行构造函数代码
	*/
	test* p = a;//创建一个指向对象数组的指针
	a[1].show();
	//test::show(test * const this);创建这个对象后就有this指针指向这个对象//test::show(&a[1]);//相当于传入当前对象的地址，const以*为界
	(p + 1)->show();
	1[a].show();//x[y]=*(x+y)=*(y+x)=y[x];
	
	//string类总结
	char* str = "name";
	char str1[] = "name";
	string s1 = "name";//=重载赋值
	string s2("name");//隐式构造赋值
	string* ptr = new string("name");
	cout << str << str1 << s1 << s2 << *ptr << endl;
	delete ptr;
	//string类的方法
	string mm1 = "hello";
	string mm2 = "world";
	//复制
	string mm3;
	mm3 = mm1;
	cout << mm3 << endl;
	//[]重载 下标访问
	cout << mm1[0] << endl;
	//拼接
	cout << mm1 + mm2 << endl;
	//交换
	mm1.swap(mm2);
	cout << mm1 << endl;
	//比较
	bool TF = mm1 > mm2;
	cout << TF << endl;
	//长度
	cout << mm1.length() << endl;
	//子串
	string temp = mm1.substr(0, 3);
	cout << temp << endl;
	
	C* pc = new C;
	delete pc;
	cout << "--------" << endl;
	{
		C cc;//查看构造顺序和析构顺序
	}
	cout << "--------" << endl;
	A* paa = new A[3];
	cout << *((int*)paa - 1) << endl;//这个也就是说在堆内存之前还有4个字节的int型内存空间存放了表示开辟了多少个堆内存
	delete[] paa;
}
