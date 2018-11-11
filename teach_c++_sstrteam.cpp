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
	//字符串流
	//将字符串转化成数字 等效于sprintf
	string  res = "100";
	int num;
	stringstream sst;
	sst << res;
	sst >> num;
	cout << num << endl;
	//分割字符+类型转换
	string ip = "192.168.1.1";
	stringstream sst2(ip);//使用构造方法 相当于sst2<<ip;
	int a1, a2, a3, a4;
	char ch;
	sst2 >> a1 >> ch >> a2 >> ch >> a3 >> ch >> a4;
	cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
	//拼接
	stringstream sst3;
	int num1 = 3;
	sst3 << num1 << ch << "1415926";
	string aa;
	sst3 >> aa;
	cout << aa << endl;

	student stu[3] = {
		"小马",1001,18,'m',
		"xx",100,19,'w',
		"ss",1000,20,'w'
	};
	//输入把缓冲区的拿出来 ofstream outfile;
	
	ofstream outfile("stu.dat", ios::binary);//相当于使用构造
	//ofstream outfile;
	//outfile.open("stu.dat", ios::binary);
	if (!outfile)
	{
		cerr << "open error" << endl;
		//exit(-1);//退出
		abort();//退出
	}
	for (int i = 0; i < 3; i++)
	{
		outfile.write((char*)&stu[i], sizeof stu[i]);//第一个必须是const char*类型,//(char*)&stu[i]转类型地址不受影响
		//相当于把一个&stu[i]类型的指针变成char*，只是指向大小变了，但是指向地址不变，强转秘诀：只要地址一致
	}
	outfile.close();
	//用二进制写进去所以
	//读
	student rstu[3];//怕爆栈可以在堆上申请内存
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
