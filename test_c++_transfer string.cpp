#include<iostream>
#include<string>
using namespace std;
void display(string* str, int n);
int main()
{
	const int Size = 3;
	char kk[200];
	cin >> kk;
	cout << kk << endl;;
	//cin.clear();������ֻ�����cin�Ĵ���״̬���������������
	cin.getline(kk,100);//���ۣ�ʹ��cin.getline��סʣ�µ��ַ�,�൱���������
	cout << kk << endl;;
	char str[100];
	cin.getline(str, 100);//cin.getlineֻ�ܸ�char���͸�ֵcin.getline��iostream��ģ�getlineֻ�ܸ�string���͸�ֵ����Ϊgetline��������string���
	string name[Size];//����string���Ͷ����ַ������鷽��
	for (int i = 0; i < Size; i++)
	{
		getline(cin,name[i]);//����ʹ��cin.getline(name[i],100]Ϊstring�����ֵ
	}
	display(name, Size);//����name���У�name�������һ����ַ
}

void display(string* str, int n)//string���ͺ�char��ʹ�÷�ʽһ��
{
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << endl;
	}
}