#include<iostream>
using namespace std;
class A
{
public:
	int m_a{ 10 };//���ڳ�ʼ��
	A(const A& other){ }//д�˹����û��Ĭ���޲ι�����
	A() = default;//��ԭĬ��
	//A(const A& other) = delete; ��ŵ�privateһ��
};
class B
{
private:
	int m_a, m_b, m_c;
public:
	B(int a, int b, int c):m_a(a),m_b(b),m_c(c){ }
	B():B(10,20,30){ }//�޲�ί�����ι���
	void show() { cout << m_a << m_b << m_c << endl; }

};
int main()
{
	//���� long
	cout << sizeof(int) << endl;//x86 4λ  x64 8λ��debug��߿��Ե�������һ���ƽ̨��long
	cout << sizeof (long long) << endl;
	int* p = nullptr;//�ڲ�����0���߼����ǿ�  null��0ָ��
	cout << p << endl;
	using dtype = int;//����ȡ�����������ڳ�������
	dtype dt = 20;
	cout << typeid(dt).name() << endl;
	//��ֵ�Զ�ʶ������
	auto ai = 10;

	A a;
	cout << a.m_a << endl;
	int arr[5] = { 1,2,3,4,5 };
	int arr1[]{ 1,2,3,4,5 };//����ʽ��ֵ
	//��Χforѭ��
	for (auto i : arr)
	{
		cout << i << endl;
	}
	//��ֵ����
	int num = 10;
	int& l_num = num;//��ֵ����
	int&& r_num = 10;//��ֵ����
	//�ƶ����壨�ƶ��������ƶ������Ժ���ֵû��

	//lambda���ʽ(��������)
	auto sum = [](int a, int b) {return a + b; };
	//����ָ��ʽһ����:Ψһָ��,����ָ�룬�Զ��ͷ�unique_ptr shared_ptr
	//final д�ұ�
	//�౻final���β��ܱ��̳�
	//virtual������final���β��ܱ���д 

}