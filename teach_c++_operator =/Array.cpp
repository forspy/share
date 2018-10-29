#include "Array.h"
#include<iostream>


my_Array::my_Array(int size)
{
	cout << "构造" << endl;
	m_array = new int[size];
	m_size = size;
}

my_Array::my_Array(my_Array & arr)
{
	cout << "拷贝构造" << endl;
	m_array = new int[arr.m_size];
	memcpy(m_array, arr.m_array, arr.m_size * sizeof(arr.m_array[0]));
	m_size = arr.m_size;
}


my_Array::~my_Array()
{
	if (this->m_array)
		delete[] m_array;
}
