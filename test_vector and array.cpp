#include<iostream>
#include<vector>//STL C++98 模板类
#include<array>//C++11 模板类

int main(int agrc, char* argv[])
{
	using namespace std;
	vector<int> vi(100,1) ;//创建一个int类型的长度为1的数组并初始化为1，这里的数组被称为对象
	vector<int> vi1(1);
	int a[10];
	double *p;
	cout << vi[99]<<endl<<sizeof vi << endl<<sizeof p<<endl;//已解决：vector 创建的是针指，
	//vector的四个成员变量_A allocator;iterator _First, _Last, _End; 因此大小始终是16字节，区别于数组的创建是实体的创建
	cout <<"vector创建的数组大小为"<< vi.size() << endl;//用这种方法可以查看vector创建数组的大小
	//vector <typename> vt(n_elem)  n_elem是一个变量也可以是常量
	
	//array<typename,n_elem> arr ,array的n_elem不能是变量
	vi[0] = 0;
	vi[1] = 1;
	vi[2] = 2;//STL vector只能这样初始化

	//vector储存在堆里，array储存在栈里，所以array的效率比较高

	array<int, 5> ai = { 1,2,3,4,5 };//创建一个5个元素的array并初始化
	array<int, 5>ai2;
	ai2 = ai;//1.array的对象是可以赋值给另一个变量的2.变量的类型和大小必须一样
	cout << ai2[0] << endl;
	ai2.at(0) = 9999;//也可以使用成员函数at()对数组赋值,可以防止数组下标越界
	
	cout << ai2[0] << endl;
}