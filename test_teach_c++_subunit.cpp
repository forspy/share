#include<iostream>
using namespace std;
void func(int, int b, int)//Ϊ�˲�Ʒ��������ģ���Ʒ��������ܲ���1�Ͳ���3��ʹ����
//Ϊ�˲���main�û�ʹ����Ĵ����Ĵ��룬����ʹ����Ԫ
{
	cout << b << endl;
}
int main()
{
	func(1, 2, 3);
}