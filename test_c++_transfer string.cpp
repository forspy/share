#include<iostream>
#include<string>
using namespace std;
void display(string* str, int n);
int main()
{
	const int Size = 3;
	string name[Size] = { "hello","world","!!!" };//����string���Ͷ����ַ������鷽��
	display(name, Size);//����name���У�name�������һ����ַ
}

void display(string* str, int n)//string���ͺ�char��ʹ�÷�ʽһ��
{
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << endl;
	}
}