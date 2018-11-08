//目标设计一个Student类，比如成员函数是姓名和数组，都是可变长度的。引入类中的类成员对象1.姓名可以使用string类对象
//2.数组可以使用模板类数组valarray
//介绍valarray：
/*
valarry是由头文件<valarray>支持的，用于处理数组数值，例如支持将数组中所有元素的值相加，以及在数组中找出最大和最小值等操作
*/
#include<valarray>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	valarray<double> v1;//声明一个double类型的0个元素的数组（valarray也需要名称空间std的支持）
	valarray<int>v2(8);//8个元素的数组
	valarray<int>v3(10,8);//8个元素的数组,每个元素设为10
	double gpa[5] = { 1,2,3,4,5 };
	valarray<double>v4(gpa, 4);//4个元素数组，4个值为gpa数组内的值
	valarray<int>v5 = { 1,2,3,4,5 };//也可以使用数组初始化
	/*
	下面是这个类的一些方法：
	[]访问元素（重载operator[]）
	size()返回包含的元素
	sum()返回元素的总和
	max()返回最大值的元素
	min()返回最小值的元素
	*/
	cout << v5.max() << v5.min() << endl;
}
