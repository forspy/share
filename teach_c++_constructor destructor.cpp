/*
QQ1-����ϵͳ--�ײ�Ӳ����tcp/ip��--�ײ�Ӳ��--����ϵͳ--QQ2
�ֲ�ʽӦ��--ACE��
����ͼ����--openCV

�������ҵT�ͷ�չ���������ٺ�����չT
endl�建��
const char* p="hello";
���ƿռ����namespace abc=a:b:c
�������ڵı�������һ���ڴ�
c++���ͼ����ϸ�
*/
/*
��������������ԣ���װ���̳С���̬
*/
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
	void show();
};

//��ʼ����
test::test()
{

}
test::test(int a):num(a)
{
	cout << "��ʼ����ʽ����"<<num << endl;
}
void test::show()
{

}
int main()
{
	test k{ 1 };//���Ƽ�ʹ��
	test* pa = new test[7];//����new����
	cout << *((int*)pa - 1) << endl;
	delete[] pa;
	test a[4];//����һ��4�����������
	test* p = a;//����һ��ָ����������ָ��
	a[1].show();
	(p + 1)->show();
	1[a].show();//x[y]=*(x+y)=*(y+x)=y[x];
}