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
#include<string>
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

//�����������˳��
class A
{
public:
	A() { cout << "A����" << endl; }
	~A() { cout << "A����" << endl; }
	/*
	ִ��������������
	������Ա����
	�������ಿ��
	�ͷ���������ռ���ڴ�
	*/
};

class B
{
public:
	B() { cout << "B����" << endl; }
	~B() { cout << "B����" << endl; }
	A aaa;
};
class C
{
public:
	C() { cout << "C����" << endl; }//�ӽ�������������Աbbb��Ҫ���ڹ��캯��ִ�е�
	~C() { cout << "C����" << endl; }//�ӽ������������������������������Ա
	B bbb;
};
int main()
{
	test k{ 1 };//���Ƽ�ʹ��
	test* pa = new test[7];//����new����
	cout << *((int*)pa - 1) << endl;
	delete[] pa;
	test a[4];//����һ��4�����������
	//���캯���Ķ��󴴽����̣�
	/*
	1.Ϊ������������ڴ�
	2.������ಿ�֣�����е㻰��
	3.�����Ա����
	4.ִ�й��캯������
	*/
	test* p = a;//����һ��ָ����������ָ��
	a[1].show();
	(p + 1)->show();
	1[a].show();//x[y]=*(x+y)=*(y+x)=y[x];
	
	//string���ܽ�
	char* str = "name";
	char str1[] = "name";
	string s1 = "name";//=���ظ�ֵ
	string s2("name");//��ʽ���츳ֵ
	string* ptr = new string("name");
	cout << str << str1 << s1 << s2 << *ptr << endl;
	delete ptr;
	//string��ķ���
	string mm1 = "hello";
	string mm2 = "world";
	//����
	string mm3;
	mm3 = mm1;
	cout << mm3 << endl;
	//[]���� �±����
	cout << mm1[0] << endl;
	//ƴ��
	cout << mm1 + mm2 << endl;
	//����
	mm1.swap(mm2);
	cout << mm1 << endl;
	//�Ƚ�
	bool TF = mm1 > mm2;
	cout << TF << endl;
	//����
	cout << mm1.length() << endl;
	//�Ӵ�
	string temp = mm1.substr(0, 3);
	cout << temp << endl;
	
	C* pc = new C;
	delete pc;
	cout << "--------" << endl;
	{
		C cc;//�鿴����˳�������˳��
	}
	cout << "--------" << endl;
	A* paa = new A[3];
	cout << *((int*)paa - 1) << endl;//���Ҳ����˵�ڶ��ڴ�֮ǰ����4���ֽڵ�int���ڴ�ռ����˱�ʾ�����˶��ٸ����ڴ�
	delete[] paa;
}