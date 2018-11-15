//多类型模板，一般构造函数可以输入两个类型以上的值
#include<iostream>
#include<string>
template<class T1,class T2>
//也可以提供默认类型template<class T1,class T2=int>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();//可以当右值，也可以当左值
	T1 first() const { return a; }//后面加const也形成重载，只能当右值
	T2 second() const { return b; }
	Pair (const T1& aval,const T2& bval): a(aval),b(bval){ }
	Pair(){ }
};
//此外还可以使用显示完全具体化和部分具体化来限制模板的通用性
//完全具体化:template <> class Pair<cha*>{...}
//部分具体化:template<class T1>class Pair<T1,int>{...}
//程序的调用优先级为：1.指针模板template<class T*> 2.具体化模板 3.普通模板

template<class T1,class T2>
T1& Pair<T1, T2>::first()
{
	return a;//返回一个类型为T1的成员变量
}

template<class T1,class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}

int main()
{
	using namespace std;
	//注意Pair<char*,int>与下面是完全不同的两个类型
	Pair<string, int> rating[4] = {
		Pair<string,int>("xiaoming",5),
		Pair<string,int>("xiaowang",4),
		Pair<string,int>("xiaozhang",3),
		Pair<string,int>("xiaohong",2),
	};//初始化完要写;
	int joints = sizeof(rating) / sizeof (Pair<string, int>);//对象数组的大小除以一个对象的大小等于对象数组的个数
	cout << "Rating:\t eatery" << endl;
	for (int i = 0; i < joints; i++)
	{
		cout << rating[i].second() << "\t" << rating[i].first() << endl;
	}
	//更改其中一个对象的成员函数
	rating[3].first() = "xiaohua";
	rating[3].second() = 1;
	cout << rating[3].second() << "\t" << rating[3].first() << endl;
}
