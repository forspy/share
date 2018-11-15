#include<iostream>
using namespace std;
//友元函数也可以有模板约束
template<typename T> void counts();//被模板类约束的友元
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
	friend void counts<TT>();//友元函数加入了模板的限制
	friend void reports<>(Hasfriend<TT>&);//声明在类中只是为了获得权限，是一种权限声明,(<>自动读取参数的类型)
};

template <typename T>
int Hasfriend<T>::ct = 0;//类外初始化静态变量,表示很多类型都初始化为0了哪一种T定义一个对象就加一次该类型的静态成员

//加约束后的模板类友元需要在实现前面写上友元类模板
template<typename T>
void counts()//实现的时候可以不写模板类
{
	//这里的T是友元类型的T不同于模板的T
	cout << "template size:" << sizeof(Hasfriend<T>) << ";";//友元函数访问成员变量
	cout << "template count:" << Hasfriend<T>::ct << endl;
}

template<typename T>
void reports(T& hf)//友元函数访问模板类对象成员变量
{
	cout << hf.item << endl;//
}

int main()
{
	cout << "没有对象声明" << endl;
	counts<int>();//直接使用友元函数
	//-----
	Hasfriend<int> hfil1(10);
	cout << "在对象hfil1定义之后" << endl;
	counts<int>();
	//------
	Hasfriend<int> hfil2(20);
	cout << "又加了一个对象hfil2之后" << endl;
	counts<int>();
	//------
	Hasfriend<double>hfdb(10.5);
	cout << "换了一个类型初始化" << endl;
	counts<double>();
	//-------
	reports(hfil1);
	reports(hfil2);
	reports(hfdb);
}