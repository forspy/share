#include<iostream>
#include<string>
using namespace std;
class A
{
private:
	const int m_a;//��Ҫ�ó�ʼ���б��ʼ��
	int a;
	int b;
public:
	A();
	A(int data);
};

A::A() :m_a(0)//��Ĭ�ϵ�һ��ֵ���У����û�������
{

}

A::A(int data) : m_a(data), a(10), b(b)//��˳��
{

}

class student
{
public:
	student(string const& name, int age) :m_name(name), m_age(age) {}
	//void print(/*�൱��const student* this */) const { cout << m_name << "," << m_age << endl; }   //��Ϊ��ʽthis������һ�������벻const�������أ�������const
	void print() { cout << m_name << "," << m_age++ << endl; }
private:
	string m_name;
	mutable int m_age;//mutable�ɱ��죬͵͵��һ�����ſ�ʹ��const����Ҳ�����޸�
};

int main()
{
	student stu("hello", 12);
	stu.print();//��const������Ե������������ȵ���һ�㣬���û�к���const����ʹ��һ�㺯��
	stu.print();
	const student stu1("hello", 99);//const����ֻ�ܵ��ú���const
	stu.print();
	int a = 1;
	int const* p = &a;//const��*Ϊ����const int*p �ȼۣ����ܸ�a����
	int* const pp = &a;//�����޸�ָ��
}