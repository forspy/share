#include<iostream>

using namespace std;
struct inflatable//�ṹ
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	inflatable guest =
	{
		"Glorious Gloria",
		1.88f,//�����ͱ�ʾ���������ֺ����f
		29.99
	};
	//guest={"Glorious Gloria",1.88f,29.99};
	//cout << sizeof inflatable << endl;��������ṹ��Ĵ�С
	cout << guest.name << guest.volume << endl;
	inflatable others;
	others = guest;//c++�ṹ�嵽�ṹ��ĸ�ֵ
	cout << others.name << endl;
	enum hi{one,two,three};//ö��  Ϊ0��1��2
	cout << one<< endl;
	union oneof//����
	{
		int i;
		double j;
	};
	oneof test;
	test.i = 1;
	//test.j = 1.0;
	cout << test.i;//ֻ��һ���ǵ�ǰ�ĳ�Ա���������������ֵ��ȡ��һ��
}

