#include<sstream>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	char name[20];
	int num;
	int age;
	char sex;
};

int main()
{
	//�ַ�����
	//���ַ���ת�������� ��Ч��sprintf
	string  res = "100";
	int num;
	stringstream sst;
	sst << res;
	sst >> num;
	cout << num << endl;
	//�ָ��ַ�+����ת��
	string ip = "192.168.1.1";
	stringstream sst2(ip);//ʹ�ù��췽�� �൱��sst2<<ip;
	int a1, a2, a3, a4;
	char ch;
	sst2 >> a1 >> ch >> a2 >> ch >> a3 >> ch >> a4;
	cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
	//ƴ��
	stringstream sst3;
	int num1 = 3;
	sst3 << num1 << ch << "1415926";
	string aa;
	sst3 >> aa;
	cout << aa << endl;

	student stu[3] = {
		"С��",1001,18,'m',
		"xx",100,19,'w',
		"ss",1000,20,'w'
	};
	//����ѻ��������ó��� ofstream outfile;
	
	ofstream outfile("stu.dat", ios::binary);//�൱��ʹ�ù���
	//ofstream outfile;
	//outfile.open("stu.dat", ios::binary);
	if (!outfile)
	{
		cerr << "open error" << endl;
		//exit(-1);//�˳�
		abort();//�˳�
	}
	for (int i = 0; i < 3; i++)
	{
		outfile.write((char*)&stu[i], sizeof stu[i]);//��һ��������const char*����,//(char*)&stu[i]ת���͵�ַ����Ӱ��
		//�൱�ڰ�һ��&stu[i]���͵�ָ����char*��ֻ��ָ���С���ˣ�����ָ���ַ���䣬ǿת�ؾ���ֻҪ��ַһ��
	}
	outfile.close();
	//�ö�����д��ȥ����
	//��
	student rstu[3];//�±�ջ�����ڶ��������ڴ�
	ifstream infile("stu.dat", ios::binary);
	if (infile)
	{

	}
	for (int i = 0; i < 3; i++)
	{
		infile.read((char*)&rstu[i], sizeof rstu[i]);
	}
	infile.close();
	for (int i = 0; i < 3; i++)
	{
		cout << rstu[i].name << endl;
	}

}
