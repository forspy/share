#include<iostream>
#include"overload.h"

int main()
{
	//������
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planing time=";
	planning.show();
	cout << endl;

	cout << "coding time=";
	coding.show();
	cout << endl;

	cout << "fixing time=";
	fixing.show();
	cout << endl;

	//total = coding.sum(fixing);//�õ���coding�����minutes
	total = coding + fixing;//ΪTime�������+���㣨+���ƺ������أ��ȼ���total = coding.operator+(fixing);
	Time together;
	together = total + coding + fixing;//Ҳ���Զ������൱��total.operator+(coding+fixing)
	
	cout << "coding.sum(fixing)=";
	total.show();
	cout << endl;

	total = total - fixing;
	cout << "total - fixing=";
	total.show();
	cout << endl;

	total = total * 2;
	cout << "total*2=";
	total.show();
	cout << endl;
	
	coding = 2 * coding;//��д����Ԫ���������ʹ�ý�������,��Ԫ����ӿڵ���չ
	//coding = operator*(2, coding);//�ȼ�
	cout << "2*coding=";
	total.show();
	cout << endl;
}