#include<iostream>

using namespace std;
int main()
{
	int a[5] = { 1,2,3,4,5 };
	for (int x : a)//c++11写法
	{
		x--;
		cout << x << endl;
	}
	for (int &y : a)//&y表示引用变量对y操作其实是修改数组a里面的值
		y = y + 1;
	for (int z : a)
		cout << z << endl;
	for (int k : {1, 3, 5, 7, 9})
		cout << k << endl;
}