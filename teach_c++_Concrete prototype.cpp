#include<iostream>
using namespace std;

//��ȫ���廯ԭ��

template<typename T>
T max(T a, T b)
{
	cout << typeid(T).name() << endl;
	return a > b ? a : b;
}
//��ȫ���廯ԭ��
template<>
const char* max(const char* a, const char* b)
{
	return strcmp(a, b) >0 ? a : b;//������廯�����þ����ֳ�����
}

template<typename T>
class Stack
{

};
//��ȫ���廯
template<>
class Stack<bool>
{

};
//���־��廯
//template<typename T,typename Allocator>//�ڴ湹����
//class vector<bool, Allocator>//ָֻ��bool
//{
//
//};
//��ģ��Ĳ��־��廯����ȫ���廯�����Ƕ��������
//ƥ���ʱ������ƥ��ָ�����͵ģ�Ȼ���Ǿ��嵽����
template<typename T, typename A>
class Test
{
public:
	Test() { cout << "����" << endl; }
	T a;
	A b;
};
//���磺���־��廯
template<typename A>
class Test<int,A>
{
public:
	Test() { cout << "���־��廯" << endl; }
	int a;
	A b;
};
//���磺��ȫ���廯
template<>
class Test<int, int>
{
public:
	Test() { cout << "��ȫ���廯" << endl; }
	int a;
	int b;
};
int main()
{
	cout << max(5, 10) << endl;
	cout << max("hello", "world") << endl;
	//�������õ��Ƿ��ͺ��� return a > b ? a : b;�������Ƚϵ��ǵ�ַ��λ ����λ���������hello
	/*���ӣ�
	template<>
	const char* max(const char* a, const char* b)
	{
	return strcmp(a, b) >0 ? a : b;
	}
	֮��cout << max("hello", "world") << endl;�����world����Ϊstrcmp
	*/
	Test<int,double> ss1;
	Test<double, double> ss2;
	Test<int, int> ss3;
	//��ģ��Ĳ��־��廯����ȫ���廯�����Ƕ��������,�Լ����廯����ʵ�����ڵĲ�ͬ����
}