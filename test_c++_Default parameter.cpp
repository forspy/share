//��û������������Ӳ���ʱ��������ú���ʹ��Ĭ��ֵ��������ں���ԭ���и�������Ĭ��ֵ
//ͨ��ʹ��Ĭ�ϲ��������Լ���Ҫ��������������������Լ��������ص�����
#include<iostream>
const int SIZE = 80;
using namespace std;
char* left(const char* str, int n = 1);//nΪҪ��ȡ���ַ���,Ĭ��n=1Ϊ��ȡ��ߵ�һ���ַ�
int main()
{
	char name[SIZE];
	cout << "enter a string" << endl;
	cin.getline(name, SIZE);
	char* ps = left(name, 4);
	cout << ps << endl;
	delete[] ps;
	ps = left(name);
	cout << ps << endl;
	delete[] ps;
}

char* left(const char* str, int n)//nΪҪ��ȡ���ַ���
{
	if (n < 0)
		n = 0;
	//Ҳ�����Ȳ�ⳤ��
	//int len=strlen(str) ������Ч����,��Ҫ#include<cstring>
	//n=(n<len)?n:len;
	//char* p=new char[n+1];
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n&&str[i]; i++)
	{
		p[i] = str[i];//�����ַ���������
	}
	p[i] = '\0';
	return p;
}