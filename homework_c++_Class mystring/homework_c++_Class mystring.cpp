#include"Mystring.h"

int main()
{
	char* p = "test";
	Mystring A;
	A = p;//��һ�����ô��ι��캯��
	cout << A << endl;
	Mystring B("hello");
	Mystring C(" world!!!");
	Mystring D = B + C;
	cout << B<<"+"<<C<<"="<<D << endl;

	cout << B << "+=" << C << "Ϊ";
	B += C;
	cout << B << endl;
	Mystring E;
	cin >> E;
	cout <<"������Ϊ��"<< E << endl;
	int i = 1;
	cout << "��"<<i<<"���ַ���"<<E[i] << endl;
	cout << E << "�ĳ���Ϊ" << E.length() << endl;
}