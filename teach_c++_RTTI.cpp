#include<iostream>
using namespace std;
class A
{
public:
	virtual void foo()
	{
		cout << "A::foo����" << endl;
	}
};

class B :public A
{
public:
	void foo()
	{
		cout << "B::foo()" << endl;
	}
};

int main()
{
	//const_cast;
	//reinterpret_cast;
	//static_cast<Ŀ������>(ԭ���ͱ���),1.������ʽ����ת����������
	//2.��ʿ����ת������ת��
	double adouble = 11.11;
	void* pv = &adouble;
	//void* pv1 = static_cast<void*>(&adouble);
	double* pv2 = static_cast<double*>(pv);
	A a;
	B b;
	A* pa = &b;//����ת��ʱ��ȫ�ģ�����ʽ����ת�� ��ȫ
	cout << typeid(pa).name()/*class A*/ << endl;//typeidʱ������ʱ���͵�typeid(pa)==typeid(pb)���Ͳ�һ�����׳��쳣-----
	B* pb = static_cast<B*>(&a);//����ȫ������ת��,û��RTTI
	cout << typeid(pb).name()/*class B*/ <<pb<< endl;
	B* pb1 = dynamic_cast<B*>(&a);//��̬����ʶ�� ��ȫ
	cout << typeid(pb1).name()/*class B*/ << pb1 << endl;//����ָ�벻һ���׳�NULL ���������׳�bad_typeid�쳣
	B* pb2 = dynamic_cast<B*>(pa);
	cout << typeid(pb2).name()/*class B*/ << pb2 << endl;
	//static_cast����ʱת�� dynamic_cast������ʱ����//��̬��ת��ֻ��ǿ�Ƶ�ת��ȥ������ʵ�ʷ���û�е������ʱ��ͻᱨ����̬��ת�����о͸������NULL��bad_typeid�쳣
}