/*
�����ڴ���� 
string 28�ֽ�
���С������ ������ռ�ڴ�
��ʲôҲ��дռ1�ֽ�
�������˹��캯����������������ṩĬ�Ϲ��캯��

*/
#include<iostream>
using namespace std;
class test
{
private:
	int num;
public:
	test();
	test(int a);
};
//��ʼ����
test::test()
{

}
test::test(int a):num(a)
{
	cout << "��ʼ����ʽ����"<<num << endl;
}

int main()
{
	test k{ 1 };//���Ƽ�ʹ��
	test* pa = new test[7];
	cout << *((int*)pa - 1) << endl;
}