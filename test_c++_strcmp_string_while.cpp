#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char word[5] = "?ate";
	for (char a = 'a'; strcmp(word, "mate"); a++)//��0��Ϊture  0��Ϊfalse
	{
		word[0] = a;
		cout << word<< endl;
	}
	cout << "ʹ��string��������ˣ����¶����ˣ���ϵ�����\n";
	string name = "?ate";
	for (char b = 'a'; name != "mate"; b++)
	{
		name[0] = b;
		cout << name << endl;
	}
}