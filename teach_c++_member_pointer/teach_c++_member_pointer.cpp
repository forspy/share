#include"Integer.h"
#include<iostream>
using namespace std;
int main()
{
	Integer i1(10), i2(20);
	//��ָͨ�룺ͨ��ȡ��ַ����-----
	int* p1 = &i1.m_i;
	int* p2 = &i2.m_i;
	cout << p1 << endl;
	cout << p2 << endl;
	//----------------
	//��Աָ�� ��ʾ���Ǹó�Աָ���������������ƫ��ֵ
	//�ӽ���Զ�����ҵ�����������
	int Integer::* p = &Integer::m_i; //(int Integer::)��Integer�����int���͵Ķ���2.Ҫ��������һ�£����ʵ�����ʵ��ƫ��ֵ
	cout << *(int*)&p << endl;//ƫ��ֵ��ʵ�Ͷ����޹أ��κζ���ĸó�Ա�������ƫ��ֵ
	//*p��ʵ������ǳ�Ա
	cout << "��Pֱ�����" << endl;
	//cout << p << endl;//
	//ͨ��.*����Աָ��ָ��ĳ�Ա��ֵ�����i1��һ������ָ����Ϊ->*��
	i1.*p = 50;
	A a;
	int A::* pa = NULL;
	//Ŀ�������paָ���ֵ������ַ
	cout << pa << endl;//ֱ����������ʾ0��Ϊʲô��
	cout << "------" << endl;
	cout << *(int*)&pa << endl;//(int*)&pa�ǰ�int A::���͵�ָ��pa�ĵ�ַǿ��ת����(int*)���ͣ�*(int*)&paȻ������õõ�paָ��ĵ�ַ����NULL����Ե�ַ��ƫ������
	pa = &A::m_a;
	cout << *(int*)&pa << endl;
	pa = &A::m_b;
	cout << *(int*)&pa << endl;
	cout << pa << endl;//ֱ���������֣�0/1��0��ʾû��ƫ�ƣ�1��ʾ��ƫ�Ƶ��ǲ������ƫ��������Ҫǿת
	//���Ͻ����ʾ��ָ�����Զ���ƫ�ƣ����Խг�Աָ��
	//ǿת����Ա�����Ӱ�죬�൱�ڱ�������һ���������ͽ��ͳ���һ����������

	A aa = 10;
	//B bb = 10;//��������ʽת���Ͳ�����
	B bb1(10);
	//���� ��������ʵ����ǿ������ת�����ٸ�ֵ������д����ʽ��Ч�ʸ�
	B bb2 = (B)10;
	B bb3 = B(10);
	cout << bb1.show() << bb2.show() << bb3.show() << endl;

	//C++����ת��
	double num = 0.03;
	cout << (int)num << endl;//c���ǿ������ת��������ı�num�ڴ棬ֻ��ı��������������num��ʱ����Ϊint����
	//��ȻҲ���԰�int����һ����
	cout << int(num) << endl;

	//const_castר������ȥ��const
	int i = 49;
	const int* pc1 = &i;//�����const��ʾ�����޸�i��ֵ
	//int* p1 = pc1;//�����ǲ��еģ���Ϊ���������ô*pc1�Ϳ���ȥ�޸�i����const int* pc1=&i;����i�ǲ��ܱ��޸ĵģ��γɳ�ͻ
	//���Եó���const int*���Ͳ���������ʼ��int*���ͣ���c++����ǿ��������һ��
	//�������
	//1.c���ȥ��
	 p1 = (int*)pc1;
	char* str = (char*)"hello world";//ע����vs2017����ᱨ��
	//2.ʹ��c++�����ȥ��const_cast
	str = const_cast<char*>("hello world");//ȥ��

	//��Ȥ�����
	const int  rmb = 100;
	const int* ppp = &rmb;
	int* qqq = const_cast<int*> (ppp);
	*qqq = 200;
	cout << *qqq << *ppp << rmb << endl;//200 200 100
	cout << qqq << ppp << &rmb << endl;//��ַ��һ��
	//���ƣ��Ĵ�������ȡ�ڴ棬�ٶ��Ĵ��� ����100�������ĳ��� rmb��ջ����ͨ����ֻ������������������޸�
	//�Ĵ�������rmbǰ���const�Ͳ���ȥ��������ڴ棨�����ڴ�ȷ�ϣ���ֱ�Ӷ�100
	volatile const int m_rmb = 100;
	volatile const int* m_ppp = &m_rmb;
	int* m_qqq = const_cast<int*> (m_ppp);
	*m_qqq = 200;
	cout << *m_qqq << *m_ppp << m_rmb << endl;//200 200 100
	cout << (int*)m_qqq << (int*)m_ppp << (int*)&m_rmb << endl;//��ַ��һ�� //��volatile const int *��: ��ֵǿ��Ϊ����ֵ��true����false��(���ܾ���),����һ���Ĵ���,����(int*)ǿתһ��
	//��Ƭ�� Ƕ��ʽ���泣�õ�volatile ���Ĵ����򽻵� Ҫ�üĴ������ڴ������ֵһ��
	//mutalbeҲ�ǿɱ�ģ��Ժ�
}