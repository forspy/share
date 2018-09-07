#include<iostream>
#include<string>
using namespace std;
struct test& ref_func(struct test& a, const struct test& b);

struct test
{
	string name;
	int value;
};
int main()
{
	struct test one = { "first",1 };
	struct test two = { "second",2 };
	cout << ref_func(one, two).value << endl;//ref_func����һ�����ã��൱��ʹ��one
	cout << one.value << endl;
	one = { "first",1 };
	cout << ref_func(ref_func(one, two), two).value << endl;//��������������ֵ��Ϊ������������
	cout << one.value << endl;//�����ı���one����
	ref_func(one, two).name = "return & ref_value is a left_value!";//ע�⣺��ֵ��������������ص����ã���ʾһ�����޸ĵ��ڴ�飬��ֵ�����淵������,����ʱ�ڴ浥Ԫ������ͨ����ַ���ʵ�ֵ
	cout << one.name << endl;
}

struct test& ref_func(struct test& a, const struct test& b)
{
	a.value = a.value+b.value;
	return a;//���ص���ʵ��one��a����������struct test ref_func�����ص���one��a���Ŀ����������������ڴ������ʱ�䣩
}