#include<iostream>
using namespace std;
double afunc(int n);
double bfunc(int n);
void estimate(int n, double(*pf)(int));
int f1(int);
int f2(int);
int f3(int);
int main()
{
	//���ܣ�ָ������ָ�������ں����ܶ������£�ʹ��ָ����ò�ͬ�ĺ��������㺯���ĵ���
	//process(think)��think()�����ĵ�ַ��Ϊ��������process����
	//process(think())��think()�����ķ���ֵ��Ϊ��������process����
	//double pam(int)
	//double (*pf)(int)
	//*pf=pam;����pam�ǵ�ַ pf��ָ�룬ָ������Ҫȥ�����ͷ���ֵ��һ��
	//����������estimate(50,pam);
	//Ҳ����������double y=(*pf)(5); double y= pam(5)

	int line;
	cout << "��Ҫ���У�" << endl;
	cin >> line;
	estimate(line, afunc);
	estimate(line, bfunc);
	//----------------------����ָ������
	int(*p1)(int) = f1;
	cout <<"��ֵ"<< (*p1)(1) << endl;
	//auto�����Զ�ʶ�����ͶԵ�ֵ���г�ʼ��
	auto p2 = p1;
	cout<<"��ֵ"<<(*p2)(1) << endl;
	//------------------
	//typedef������
	typedef int(*def)(int);
	def ptr = f3;
	cout << "ʹ��typedef�򻯶���" << (*ptr)(3) << endl;
	//------------------------------
	int(*p[3])(int) = { f1,f2,f3 };
	auto pp = p;
	for (int i = 0; i < 3; i++)
	{
		cout << (*p[i])(i) <<"auto"<< (*pp[i])(i) << endl;//�������ú���[]�����ȼ���*��������ȷ��������ַ���������
	}
}
int f1(int n)
{
	return n;
}
int f2(int n)
{
	return n;
}
int f3(int n)
{
	return n;
}



double afunc(int n)
{
	return 0.05*n;
}
double bfunc(int n)
{
	return 0.1*n;
}
void estimate(int n, double(*pf)(int))
{
	cout << "��Ҫ" << (*pf)(n) << "��" << endl;
}