#include<iostream>
using namespace std;

int main()
{
	int row, col;
	cout << "请输入动态数组大小row column" << endl;
	cin >> row >> col;
	int**p = new int* [row];//创建一排指针数组
	//为每个指针开辟一维动态数组
	for (int i = 0; i < row; i++)
	{
		p[i] = new int[col];
	}
	//使用二维动态数组
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p[i][j] = i*col + j;//赋值
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << p[i][j]<<" ";
		}
		cout << endl;
	}
	//释放
	//1.先释放指针数组中一个指针对应的一维动态数组内存
	//2.再释放一排指针数组
	for (int i = 0; i < row; i++)
		delete[] p[i];
	delete[] p;
	//p = NULL;//养成好习惯
}