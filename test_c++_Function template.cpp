//���ڲ�ͬ����ʹ��ͬһ���㷨ʱ������ʹ�ú���ģ��
//����ģ���ʹ�÷�ʽ���磺template<typename T>
//1.�ؼ���template��typename�Ǳ����
//2.����ʹ�ü�����
//3.��������������ѡ��
//4.�����ڽ�β��;
//5.�ں���ԭ�ͺ;��庯������Ҫ����һ��
#include<iostream>
template<typename T>//template<calss T> Ҳ��
void my_swap(T& a, T& b);
using namespace std;
template<typename T>
void my_swap(T& a, T& b, T& c);//�������Ľ������ ����ģ�������ͬ��T���������Ҫ��ͬ
int main()
{
	int i = 1;
	int j = 2;
	my_swap(i, j);
	//swap(i, j);//c++��д����swap
	cout << "i=" << i << endl << "j=" << j << endl;
	double m = 2.33;
	double n = 3.14;
	my_swap(m, n);
	cout << "m=" << m << endl << "n=" << n << endl;
	int o = 111;
	int p = 222;
	int q = 333;
	my_swap(o, p, q);
	cout << "o=" << o << endl << "p=" << p << endl << "q=" << q << endl;
}
template<typename T>//template<calss T> Ҳ��
void my_swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<typename T>
void my_swap(T& a, T& b, T& c)//�������Ľ����������ģ��
{
	T temp;
	temp = a;
	a = b;
	b = c;
	c = temp;
}