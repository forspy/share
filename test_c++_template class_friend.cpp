#include<iostream>
using namespace std;
template<typename T>
class Hasfriend
{
private:
	T item;
	static int ct;
public:
	Hasfriend(const T& i) :item(i) { ct++; }
	~Hasfriend() { ct--; }
	friend void counts();
	friend void reports(Hasfriend<T>&);
};

template <typename T>
int Hasfriend<T>::ct = 0;//�����ʼ����̬����,��ʾ�ܶ����Ͷ���ʼ��Ϊ0����һ��T����һ������ͼ�һ�θ����͵ľ�̬��Ա

void counts()
{
	cout << "int count:" << Hasfriend<int>::ct << ";";//��Ԫ�������ʳ�Ա����
	cout << "double count" << Hasfriend<double>::ct << endl;
}

void reports(Hasfriend<int>& hf)//��Ԫ��������ģ��������Ա����
{
	cout << "Hasfriend<int>:" << hf.item << endl;
}

void reports(Hasfriend<double>& hf)//��Ԫ����ʵ������
{
	cout << "Hasfriend<double>:" << hf.item << endl;
}

int main()
{
	cout << "û�ж�������" << endl;
	counts();//ֱ��ʹ����Ԫ����
	Hasfriend<int> hfil1(10);
	cout << "�ڶ���hfil1����֮��" << endl;
	counts();
	Hasfriend<int> hfil2(20);
	cout << "�ּ���һ������hfil2֮��" << endl;
	counts();
	Hasfriend<double>hfdb(10.5);
	cout << "����һ�����ͳ�ʼ��" << endl;
	counts();
	reports(hfil1);
	reports(hfil2);
	reports(hfdb);
}