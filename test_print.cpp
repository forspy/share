#include<iostream>//�������ͷ�ļ�
#include<cmath>
void simon(double);//����һ������ԭ��
int stonetolb(int);
using namespace std;//1.make definitions visible ʹ��count��endl��ǰ�ᣬʹ�ó������ʹ��std���ƿռ��еĶ���
//2.���������ں����⣬��������ĺ�������Ҫ�ٴ�����

int main()//main��ֵ���ظ�����ϵͳ
{
	
	//2.using ����ָ�� ��ζ����ʵ��ʹ�������ƿռ䣨namespace��

	cout << "Come up and C++ me some time.";//1.contȫ����std:count�����ڵ�����û����չ��.h��ͷ�ļ�����÷�
	//2.��c++�µ�ͷ�ļ���������c
	//3.���ȥ������ָ��usingҲ������std::count������ͬ��Ч��
	//4.cout��һ��Ԥ����Ķ���
	//5.<<Ϊ���������
	//6.<<(���������)��<<(���������)��ͬ����һ����������ص�����
		cout << endl;//start a new line��endl�Ƶ���һ��
	cout << "you won't regret it!" << endl;
	int carrots;//decalare an integer variable
	carrots = 25;
	cout << carrots;
	cout << endl;
	carrots = carrots - 1;
	cout << "Now I have " << carrots << " carrots." << endl;
	cin >> carrots;//c++ input
	cout << "Now I have " << carrots << " carrots." << endl;
	//����C++����������̣�OOP���ĺ��ĸ���֮һ��
	//iostream��һ����
	//cout��ostream�е�һ�������cin��istream�е�һ������󡣣�ostream��istream����iostreamͷ�ļ��еĳ�Ա��
	//c++֮������������������Ϊ���ڴ���֧��UNIX��Macintosh��Windows��̵����
	double area;
	cin >> area;
	double side=sqrt(area);//��ʼ��
	cout << "ƽ�����ֵΪ" << side << endl;
	double answer = pow(2, 3);//pow���ݺ����������ʾ2^3;
	cout << answer<<endl;
	double coins;
	cin >> coins;
	simon(coins);
	
	int stone;
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " stone=";
	cout << pounds << " pounds"<<endl;
    return 0;
}

void simon(double n)
{
	//using namespace std;//
	cout << "Now have "<<n << " coins!"<<endl;
}

int stonetolb(int sts)
{
	int pounds = 14 * sts;
	return pounds;
}