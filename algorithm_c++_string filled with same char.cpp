#include<iostream>
using namespace std;
char* filled_with_same_char(char ch, int n);
int main()
{
	int times=10;
	char ch='a';
	char* p;
	p = filled_with_same_char(ch, times);
	cout << p << endl;
	delete[] p;
}
char* filled_with_same_char(char ch, int n)
{
	char*ptr = new char[n + 1];//����һ����̬�ַ�������,Ҫ������һλ��'\0'
	ptr[n] = '\0';
	while (n-- >0)//�����--n����Ҫ>=0
		ptr[n] = ch;//n:0-9
	return ptr;
}