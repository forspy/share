#include<iostream>
#include<string>
using namespace std;
void show(string* p);
int main()
{
	string name = "hello";
	show(&name);//���󴫵�ַ����
}

void show(string* p)
{
	cout << *p << endl;//cout�����Ļ���Ҫ����ʵ��
}