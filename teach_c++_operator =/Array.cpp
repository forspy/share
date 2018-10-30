#include "Array.h"
#include<iostream>

my_Array::my_Array(int size)
{
	cout << "构造" << endl;
	m_array = new int[size];
	m_size = size;
}

my_Array::my_Array(const my_Array & arr)
{
	cout << "拷贝构造" << endl;
	m_array = new int[arr.m_size];
	memcpy(m_array, arr.m_array, arr.m_size * sizeof(arr.m_array[0]));//总共几个*一个的大小
	m_size = arr.m_size;
}

my_Array::~my_Array()
{
	cout << "析构" << endl;
	if (this->m_array)
		delete[] m_array;
	m_array = NULL;//养成好习惯
}

int & my_Array::at(int index)
{
	return m_array[index];
}
//原理代码构建
my_Array & my_Array::operator=(const my_Array & arr)
{
	cout << "重载=拷贝赋值" << endl;
	if (this == &arr)
		return *this;//自等于检查
	//为了防止申请内存失败
	int* ptemp = new int[arr.m_size];//先创建一个temp指针去开辟内存，如果成功就把temp赋给m_array,如果失败就抛出exception
	//---------
	if (m_array)
	{
		delete[] this->m_array;//先释放已有的内存，防止内存泄漏
		m_array = NULL;
	}
	//my_Array::~my_Array();//复用析构函数也能实现
	//-----------
	//这可太渣了！
	m_array = ptemp;
	m_size = arr.m_size;//对成员m_size赋值
	//int* m_array = new int[arr.m_size];//原来直接开，现在考虑一下能否发出来，其实没有必要都会报错重来^-^
	memcpy(m_array, arr.m_array, arr.m_size * sizeof(arr.m_array[0]));
	//my_Array(*ptemp);//以上也可以复用构造实现
	return *this;
}
//高效代码复用(待深入学习)
//my_Array & my_Array::operator=(const my_Array & arr)
//{
//	cout << "重载=拷贝赋值" << endl;
//	if (this != &arr)
//	{
//		my_Array temp(arr);//考虑的能否开出内存的问题
//		swap(this->m_array, temp.m_array);//将成员指针交换指向，现在m_array指向新的内存，temp.m_array为旧的内存
//		//在作用域结束时会调用temp的析构函数释放调旧的内存，所以swap函数还是很有用的
//	}
//	return *this;
//}

ostream & operator<<(ostream & os, const my_Array & arr)
{
	for (int i = 0; i < arr.m_size; i++)
	{
		os << arr.m_array[i] << " ";
	}
	return os;
}
