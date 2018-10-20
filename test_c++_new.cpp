#include<iostream>
#include<new>//定位new运算符头文件，让new指定要使用的位置
struct test
{
	char name[20];
	int num;
};
char buffer1[50];
char buffer2[100];
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
	cout<<ar[6]<<endl;//可以访问第7个元素如果该地址被占用则保错，没有被占用则出现野指针值
	
	delete[] ar;
	//--------定位运算符
	test* p1 = new (buffer1) test;//在全局数组中buffer1中分配内存给结构test
	int* p2 = new(buffer2) int[20];//在全局数组中buffer2中分配内存给20个int类型
	std::cout << (void*)buffer2 << std::endl;//因为p2的类型与buffer2的类型不同，如果不转换将输出字符串，所以需要对buffer2做(void*)类型的转换
	//这样得到buffer2的地址，而buffer2里面存的是int类型，所以cout会输出int类型的值
	//不能用delete或delete[]释放，因为定位new开辟在静态区
}
