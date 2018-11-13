#include<iostream>
#include"ArrayTP.h"
int main()
{
	ArrayTP<int, 10>sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10> twodee;//将一个模板类作为类型进行嵌套,10行5列的二维数组

	int i, j;
	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;//sum[i]是int类型
		for (j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1)*(j + 1);
			sums[i] += twodee[i][j];//每一行的和,因为twodee[i][j]是int类型，sum[i]是int类型，所以可以+=
		}
		aves[i] = (double)sums[i] / 10;//每一行的平均
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';//twodee[i]return的是ar[i],而这里的ar类型是ArrayTP<int, 5>也就是说返回的是一个类对象，这个类对象[j]返回该类的成员是一个int类型的ar[j]
		}
		cout << ":sum=";
		cout.width(3);
		cout << sums[i] << ",average=" << aves[i] << endl;
	}
}