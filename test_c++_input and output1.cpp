#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char name[50];
	double price;
	ofstream outfile;//����һ��ofstream��Ķ���
	outfile.open("carinfo.txt");//�ص㣺������ofstream��Ķ���󣬿���ʹ�ø���ĺ���.open(),�����ļ��� 2.Ĭ�ϴ򿪷�ʽ�����ԭ�����ı��ļ��е�����
	//char filename[10];Ҳ�����ǽ��ַ�����Ϊ�������뵽.open�����ຯ����
	//outfile.open(filename)
	cout << "enter the name\n";
	cin.getline(name, 50);
	cout << "enter price\n";
	cin >>price;

	cout << fixed;//ʹ��һ�㷽ʽ��������������ǿ�ѧ������
	cout.precision(2);//С���������λ
	cout.setf(ios_base::showpoint);//��ʾС����
	cout << name << '\n';
	cout << price << '\n';
	//outfile����ĺ���ʹ�÷�ʽ��coutһ��
	outfile << fixed;
	outfile.precision(2);
	//outfile.setf(ios_base::showpoint);
	outfile << name << '\n';
	outfile << price << '\n';

	outfile.close();//�ر��ļ�
	return 0;
}