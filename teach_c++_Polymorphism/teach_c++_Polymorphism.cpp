//��̳���ר������������μ̳е�����ģ���Ϊ���ʵ�̳еĻ��������������涼���л��ಿ��
//���ò����޸Ķ���ָ������޸�ָ�����������ڶ�̬����ı���������
//�Ժ���ָ��Ķ�̬��Ϊ��
#include<iostream>
#include"test.h"
using namespace std;
int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}
int divi(int x, int y)
{
	return x / y;
}

typedef int(*func)(int, int);

int call_math(int x, int y, func funcName)
{
	return funcName(x, y);
}

class A
{
public:
	A(){ cout << "A����" << endl; }
	virtual ~A() { cout << "A����" << endl; }
	virtual void test() { cout << "A:test" << endl; }
};
class B :public A
{
private:
	int* p;
public:
	B() { cout << "B����" << endl; p = new int[10]; }
	virtual ~B() { cout << "B����" << endl; delete[] p; }//����д��virtual��������Ҳ��Ĭ��virtual
	virtual void test() { cout << "B:test" << endl; }
};
//������� virtual int func����=0�����麯�������󷽷���ֻ�д��麯��������������ࣨ�ӿ��ࣩ��������಻��ʵ��������
//2.�̳д���������Ҫ�����еĳ��󷽷�ȫ��ʵ�֣������һ��ûʵ�֣���ô���������Ϊ�������

//��һ�ַ���ʵ���麯������ָ�����
void CallVirtualFunc(void *pthis, int index = 0)
{
	void(*funptr)(void*);//����һ������ָ��
	long vptrAddr;//�����麯�����ַ
	memcpy(&vptrAddr, pthis, 4);//�Ѷ����ǰ4���ֽ�Ҳ������ָ���ַ����ȥ
	memcpy(&funptr, (long*)(vptrAddr)+index, 4);//memcpy�ķ����Ǵ������ĵ�ַ��������Ҫ��funptr�ĵ�ַ���룬
	//��funptr��һ��ָ�룬���Զ�Ӧ��long*)(vptrAddr)+indexҲ��һ��ָ�룬������һ������ָ�룬���������������һ��
	//1.��longת��long*�൱��ȡ���麯����ָ��ĵ�ַreinterpret_cast<long*>(vptrAddr)��̫ɧ��
	//2.�ı�ָ��ĵ�ַ���Ըı�ָ���ָ��int* p; int** walk=p; walk
	(*funptr)(pthis);//funptr(pthis);Ҳ����
}
//ͨ������ָ���޸�һ��ָ��
/*
int fun(void)
{
	int *buf;
	int ret;
	ret = mem_init(&buf);
	return ret;
}
int mem_init(int **buf_t)
{
	*buf_t = NULL;
	return 1;
}
*/
int main()
{
	cout << call_math(1, 2, add) << endl;
	//B b;
	A* arr[2] = { 0 };//���û���ָ���������������
	arr[0] = new A;
	arr[1] = new B;
	arr[0]->test();
	arr[1]->test();
	N n;
	Base a;//a���������һ��_vfptr,_vfptrָ��һ���麯����������ź���ָ�루����ָ��void**����_vfptr[0]��һ������ָ��(void*)��*(_vfptr[0])������ʵ����һ����������
	Child b;
	Base* p = &b;
	cout << "sizeof N:" << sizeof N << ",m_aƫ��ֵ" << offsetof(N, m_a) << ",m_bƫ��ֵ" << offsetof(N, m_b) <<endl;//�����Ա��������ƫ��
	cout << "sizeof Base:" << sizeof Base << ",m_aƫ��ֵ" << offsetof(Base, m_a) << ",m_bƫ��ֵ" << offsetof(Base, m_b) << endl;
	//virtual������ʵ����һ��ָ�룬�����Ա������˳���޹�

	//typedef void(*VFUN)();//VFUN��Ա����ָ�����ͣ�void*����ǰ���ö���ĵ�ַ,��������������Ļ�һ������õ�ַ���þͲ�������&a�����ַ�ˣ������б�
	typedef void(*VFUN)(void*);//��void*��ʾthisָ�룬��Ϊԭ��û�в�������Ҫtypedef�൱��������һ��ԭ��
	typedef VFUN* VPTR;//ָ���麯�����ָ�����ͣ���һ������ָ��
	VPTR _vfptr = *(VPTR*)&a;//ָ�������׵�ַ��
	//VFUN* _vfptr = *(VFUN**)&a;//������ָ��д��
	//Ҳ����˵һ��ָ��ָ������������ָ��ָ���麯����
	cout << _vfptr << "[" << _vfptr[0] << "," << _vfptr[1] << "]" << endl;
	_vfptr[0](&a);
	_vfptr[1](&a);
	VPTR _vfptr1 = *(VPTR*)&b;
	cout << _vfptr1 << "[" << _vfptr1[0] << "," << _vfptr1[1] << "]" << endl;
	_vfptr1[0](&b);
	_vfptr1[1](&b);
	//-----����
	cout << "----------��һ�ַ���ʹ�ú���call" << endl;//ԭ��Ҳ�Ǻ���ָ��ȡ��������ָ��
	CallVirtualFunc(&a, 0);
	CallVirtualFunc(&a, 1);
	CallVirtualFunc(&b, 0);
	CallVirtualFunc(&b, 1);
	int aa = 0;
	int bb = 99;
	int* pp = &aa;
	int* mm = &bb;
	int** walk = &pp;
	walk = &mm;
	//*walk = mm;
	//--���Խ����ֻ�޸Ķ���ָ�벢�����޸�һ��ָ���ָ����Ҫ*walk�����޸�һ��ָ���ָ��
	
}
