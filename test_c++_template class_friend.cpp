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
int Hasfriend<T>::ct = 0;//类外初始化静态变量,表示很多类型都初始化为0了哪一种T定义一个对象就加一次该类型的静态成员

void counts()
{
	cout << "int count:" << Hasfriend<int>::ct << ";";//友元函数访问成员变量
	cout << "double count" << Hasfriend<double>::ct << endl;
}

void reports(Hasfriend<int>& hf)//友元函数访问模板类对象成员变量
{
	cout << "Hasfriend<int>:" << hf.item << endl;
}

void reports(Hasfriend<double>& hf)//友元函数实现重载
{
	cout << "Hasfriend<double>:" << hf.item << endl;
}

int main()
{
	cout << "没有对象声明" << endl;
	counts();//直接使用友元函数
	Hasfriend<int> hfil1(10);
	cout << "在对象hfil1定义之后" << endl;
	counts();
	Hasfriend<int> hfil2(20);
	cout << "又加了一个对象hfil2之后" << endl;
	counts();
	Hasfriend<double>hfdb(10.5);
	cout << "换了一个类型初始化" << endl;
	counts();
	reports(hfil1);
	reports(hfil2);
	reports(hfdb);
}