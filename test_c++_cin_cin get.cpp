#include<iostream>
using namespace std;
int main()
{
	char name[20];
	cin.getline(name,20);
	char str[20];
	char s;
	cin.get(str, 3).get(s).get();//c++֧�ֺ������أ����ڿ�������Ķ������������ֻ���벿�ֲ���
	//��������ȥѰ���в�ͬ������get()�汾
	//cin >> name;
	cout << name << endl;
	cout << str << endl;
	//CTRL+Z ��enter=EOF
}