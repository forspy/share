#include<iostream>
using namespace std;
double afunc(int n);
double bfunc(int n);
void estimate(int n, double(*pf)(int));
int f1(int);
int f2(int);
int f3(int);
int main()
{
	//介绍：指向函数的指针允许在函数很多的情况下，使用指针调用不同的函数，方便函数的调用
	//process(think)把think()函数的地址作为参数传入process函数
	//process(think())把think()函数的返回值作为参数传入process函数
	//double pam(int)
	//double (*pf)(int)
	//*pf=pam;这里pam是地址 pf是指针，指向函数，要去参数和返回值均一致
	//允许这样用estimate(50,pam);
	//也允许这样用double y=(*pf)(5); double y= pam(5)

	int line;
	cout << "需要几行？" << endl;
	cin >> line;
	estimate(line, afunc);
	estimate(line, bfunc);
	//----------------------函数指针数组
	int(*p1)(int) = f1;
	cout <<"单值"<< (*p1)(1) << endl;
	//auto用于自动识别类型对单值进行初始化
	auto p2 = p1;
	cout<<"单值"<<(*p2)(1) << endl;
	//------------------
	//typedef简化声明
	typedef int(*def)(int);
	def ptr = f3;
	cout << "使用typedef简化定义" << (*ptr)(3) << endl;
	//------------------------------
	int(*p[3])(int) = { f1,f2,f3 };
	auto pp = p;
	for (int i = 0; i < 3; i++)
	{
		cout << (*p[i])(i) <<"auto"<< (*pp[i])(i) << endl;//批量调用函数[]的优先级比*高所以先确定函数地址，后解引用
	}
}
int f1(int n)
{
	return n;
}
int f2(int n)
{
	return n;
}
int f3(int n)
{
	return n;
}



double afunc(int n)
{
	return 0.05*n;
}
double bfunc(int n)
{
	return 0.1*n;
}
void estimate(int n, double(*pf)(int))
{
	cout << "需要" << (*pf)(n) << "秒" << endl;
}