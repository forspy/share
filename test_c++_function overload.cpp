//��û������������Ӳ���ʱ��������ú���ʹ��Ĭ��ֵ��������ں���ԭ���и�������Ĭ��ֵ������ͬһ���͵Ĳ�����
//ͨ��ʹ��Ĭ�ϲ��������Լ���Ҫ��������������������Լ��������ص�����
//-----------------
//��������(���ڲ�ͬ���͵Ĳ���)
//1.�������صĹؼ��Ǻ����Ĳ����б�--������������
//2.���������Ŀ��������Ͳ�ͬ���������겻ͬ
//3.���ͺ�����������Ϊһ�������꣬�磺int x��int& x
//4.�����겻����const�ͷ�const����
//5.�������Ͳ�ͬ������������ͬ������Ϊ��������
#include<iostream>
const int SIZE = 80;
using namespace std;
char* left(const char* str, int n = 1);//nΪҪ��ȡ���ַ���,Ĭ��n=1Ϊ��ȡ��ߵ�һ���ַ�
unsigned long left(unsigned long num, int n);
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
	unsigned long value = 123456789;
	cout << "enter cut size" << endl;
	int number;
	cin >> number;
	cout << left(value, number) << endl;
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

unsigned long left(unsigned long num, int n)
{
	int digits = 1;
	if (num == 0 || n == 0)
		return 0;
	unsigned long temp = num;
	while (temp /= 10)
		digits++;//�жϴ������һ���м�λ
	if (digits > n)
		for (int i = 0; i < digits - n; i++)
			num /= 10;
	return num;
}