#pragma once
using namespace std;
class my_Array//定义一个数组类
{
private:
	size_t m_size;//而在64位架构中被定义为：typedef  unsigned long size_t;
	int *m_array;
public:
	my_Array(int size);
	my_Array(my_Array& arr);//拷贝构造
	~my_Array();
};

