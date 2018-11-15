#include<iostream>
using namespace std;
//��Ԫ����Ҳ������ģ��Լ��
template<typename T> void counts();//��ģ����Լ������Ԫ
template<typename T>void reports(T&);
template<typename TT>
class Hasfriend
{
private:
	TT item;
	static int ct;
public:
	Hasfriend(const TT& i) :item(i) { ct++; }
	~Hasfriend() { ct--; }
	friend void counts<TT>();//��Ԫ����������ģ�������
	friend void reports<>(Hasfriend<TT>&);//����������ֻ��Ϊ�˻��Ȩ�ޣ���һ��Ȩ������,(<>�Զ���ȡ����������)
};

template <typename T>
int Hasfriend<T>::ct = 0;//�����ʼ����̬����,��ʾ�ܶ����Ͷ���ʼ��Ϊ0����һ��T����һ������ͼ�һ�θ����͵ľ�̬��Ա

//��Լ�����ģ������Ԫ��Ҫ��ʵ��ǰ��д����Ԫ��ģ��
template<typename T>
void counts()//ʵ�ֵ�ʱ����Բ�дģ����
{
	//�����T����Ԫ���͵�T��ͬ��ģ���T
	cout << "template size:" << sizeof(Hasfriend<T>) << ";";//��Ԫ�������ʳ�Ա����
	cout << "template count:" << Hasfriend<T>::ct << endl;
}

template<typename T>
void reports(T& hf)//��Ԫ��������ģ��������Ա����
{
	cout << hf.item << endl;//
}

int main()
{
	cout << "û�ж�������" << endl;
	counts<int>();//ֱ��ʹ����Ԫ����
	//-----
	Hasfriend<int> hfil1(10);
	cout << "�ڶ���hfil1����֮��" << endl;
	counts<int>();
	//------
	Hasfriend<int> hfil2(20);
	cout << "�ּ���һ������hfil2֮��" << endl;
	counts<int>();
	//------
	Hasfriend<double>hfdb(10.5);
	cout << "����һ�����ͳ�ʼ��" << endl;
	counts<double>();
	//-------
	reports(hfil1);
	reports(hfil2);
	reports(hfdb);
}