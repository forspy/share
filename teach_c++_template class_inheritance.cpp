#include<iostream>
#include<string>
using namespace std;
template<typename T>

class Parent
{
private:
	T m_data;
public:
	Parent(T data=0) { m_data = data; }//ǰ����T������Ҫע��=���ص����
};
//��������಻��ģ���࣬�������ʾָ�����������,����Ҫ�ù��캯���б�����ʾָ������ģ�����͹��캯����ʼ��
class ChildOne :public Parent<int>
{
private:
	int m_clone;
public:
	ChildOne(int a=0, int b=0) :Parent(b)
	{
		m_clone = a;
	}
};
//���������Ҳ��ģ���࣬Ҫô��ʽָ����������ͣ�Ҫôʹ�÷���ָ��
template<typename T>
class ChileTwo :public Parent<T>
{
private:
	int m_clone;
public:
	ChileTwo(int a = 0, T b = " ") :Parent(b)
	{
		m_clone = a; 
	}
};
int main() 
{
	ChildOne one;
	ChileTwo<string> two;//ģ���Ƕ��α���
	cout << sizeof(one) << " " << sizeof(two) << endl;

}