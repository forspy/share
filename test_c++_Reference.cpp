#include<iostream>
using namespace std;
void swap(int* a, int* b);
void swap1(int& a, int& b);
double ref_cub(const double &ra);//�����ĺ���ԭ�ͽ���ֹ�����޸�ʵ�ε�ֵ
int main()
{
	int rat = 1;
	int& ref_rat = rat;//����һ��int& ���͵����ñ���ref_rat,���ĵ�ַ��ratһ�����������ñ����ȼ��ڲ���ԭ����,һ��������������
	//�����ڶ�������ʱ�����ʼ����������ָ�룩,���ú�����һ��ȷ�����ö���㲻��ı�ָ��ĵ�ַ
	//���õȼ��� int* const ptr=rat;  ref_rat��*ptr���
	cout << rat << endl << ref_rat << endl << "&rat=" << &rat << endl << "&ref_rat=" << &ref_rat << endl;
	int bus = 2;
	ref_rat = bus;
	cout << "&ref_rat=" << &ref_rat << endl << "&bus=" << &bus << endl << "rat=" << rat << endl;//�����ñ�����ֵ��������������ı�����ñ���ָ��ĵ�ַ,����ı�ԭ���ö����ֵ

	int u;
	int v;
	u = 3;
	v = 4;
	swap(u, v);
	cout << u << v << endl;
	u = 3;
	v = 4;
	swap1(u, v);
	cout << u << v << endl;
}

void swap(int* a, int* b)//ͨ��ָ�뽻��
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap1(int& a, int& b)//ͨ�����ý���,һ��������������,�����ô��ݣ�ʹ��ʵ�γ�ʼ���βΣ����Ϲ���
//����һ����Ҫ���������ָ�룬���ʵ���������ݣ���ֵ���� 1�����γ���ʱ�������ֲ�������c++11����ʹ��int&& a=1;˫&&����ֵ����
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

