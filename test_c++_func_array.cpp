//模板array并非只能存基本数据类型，它还可以储存类对象,这里储存了string类对象
#include<iostream>
#include<array>
#include<string>
using namespace std;
const int Season = 4;
const array < string, Season > sname= {"spring", "summer", "fall", "winter"};
void filled_expense(array<double, Season> a, int n);
void filled_expense(array<double, Season> *a, int n);
void shou_expense(array<double, Season> ex, int n);
int main(int argc, char** argv)
{
	array<double, Season>expense = {0,0,0,0};//expense是一个指针，也是一个对象，一个对象是一个个体（相当于是一个变量），一个数组是一个个体，数组里的元素只是里面的成员
	filled_expense(&expense, Season);//传地址修改对象
	shou_expense(expense, Season);//相当于拷贝副本输出

}
void filled_expense(array<double, Season>* a, int n)//其实a是一个指向指针的指针，因为array<double, Season>本身就是一个指针
{
	for (int i = 0; i < n; i++)
	{
		cout << "enter " << sname[i] << " expense" << endl;
		cin >> (*a)[i];//从指针的角度考虑：a是一个指向指针的指针，所以要先*a，得到expense的地址后再解引用
		               //从对象的角度考虑a指向expense这个对象，一个对象是一个个体（相当于是一个变量），切换变量需要解引用
		//对对象的修改要小心了，注意及时解引用
	}
}
void shou_expense(array<double, Season> ex, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << sname[i] << " = " << ex[i] << endl;
	}
}
//以下是传值修改，可以看到没有修改原array数组中的值
void filled_expense(array<double, Season> a, int n)//其实a是一个指向指针的指针，因为array<double, Season>本身就是一个指针
{
	for (int i = 0; i < n; i++)
	{
		cout << "enter " << sname[i] << " expense" << endl;
		cin >> a[i];//从指针的角度考虑：a是一个指向指针的指针，所以要先*a，得到expense的地址后再解引用
		               //从对象的角度考虑a指向expense这个对象，一个对象是一个个体（相当于是一个变量），切换变量需要解引用
	}
}