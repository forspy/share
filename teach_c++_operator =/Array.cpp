#include "Array.h"
#include<iostream>

my_Array::my_Array(int size)
{
	cout << "����" << endl;
	m_array = new int[size];
	m_size = size;
}

my_Array::my_Array(const my_Array & arr)
{
	cout << "��������" << endl;
	m_array = new int[arr.m_size];
	memcpy(m_array, arr.m_array, arr.m_size * sizeof(arr.m_array[0]));//�ܹ�����*һ���Ĵ�С
	m_size = arr.m_size;
}

my_Array::~my_Array()
{
	cout << "����" << endl;
	if (this->m_array)
		delete[] m_array;
	m_array = NULL;//���ɺ�ϰ��
}

int & my_Array::at(int index)
{
	return m_array[index];
}
//ԭ����빹��
my_Array & my_Array::operator=(const my_Array & arr)
{
	cout << "����=������ֵ" << endl;
	if (this == &arr)
		return *this;//�Ե��ڼ��
	//Ϊ�˷�ֹ�����ڴ�ʧ��
	int* ptemp = new int[arr.m_size];//�ȴ���һ��tempָ��ȥ�����ڴ棬����ɹ��Ͱ�temp����m_array,���ʧ�ܾ��׳�exception
	//---------
	if (m_array)
	{
		delete[] this->m_array;//���ͷ����е��ڴ棬��ֹ�ڴ�й©
		m_array = NULL;
	}
	//my_Array::~my_Array();//������������Ҳ��ʵ��
	//-----------
	//���̫���ˣ�
	m_array = ptemp;
	m_size = arr.m_size;//�Գ�Աm_size��ֵ
	//int* m_array = new int[arr.m_size];//ԭ��ֱ�ӿ������ڿ���һ���ܷ񷢳�������ʵû�б�Ҫ���ᱨ������^-^
	memcpy(m_array, arr.m_array, arr.m_size * sizeof(arr.m_array[0]));
	//my_Array(*ptemp);//����Ҳ���Ը��ù���ʵ��
	return *this;
}
//��Ч���븴��(������ѧϰ)
//my_Array & my_Array::operator=(const my_Array & arr)
//{
//	cout << "����=������ֵ" << endl;
//	if (this != &arr)
//	{
//		my_Array temp(arr);//���ǵ��ܷ񿪳��ڴ������
//		swap(this->m_array, temp.m_array);//����Աָ�뽻��ָ������m_arrayָ���µ��ڴ棬temp.m_arrayΪ�ɵ��ڴ�
//		//�����������ʱ�����temp�����������ͷŵ��ɵ��ڴ棬����swap�������Ǻ����õ�
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
