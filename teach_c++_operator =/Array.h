#pragma once
using namespace std;
class my_Array//����һ��������
{
private:
	size_t m_size;//����64λ�ܹ��б�����Ϊ��typedef  unsigned long size_t;
	int *m_array;
public:
	my_Array(int size);
	my_Array(my_Array& arr);//��������
	~my_Array();
};

