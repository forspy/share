#include<iostream>
#include"ArrayTP.h"
int main()
{
	ArrayTP<int, 10>sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10> twodee;//��һ��ģ������Ϊ���ͽ���Ƕ��,10��5�еĶ�ά����

	int i, j;
	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;//sum[i]��int����
		for (j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1)*(j + 1);
			sums[i] += twodee[i][j];//ÿһ�еĺ�,��Ϊtwodee[i][j]��int���ͣ�sum[i]��int���ͣ����Կ���+=
		}
		aves[i] = (double)sums[i] / 10;//ÿһ�е�ƽ��
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';//twodee[i]return����ar[i],�������ar������ArrayTP<int, 5>Ҳ����˵���ص���һ���������������[j]���ظ���ĳ�Ա��һ��int���͵�ar[j]
		}
		cout << ":sum=";
		cout.width(3);
		cout << sums[i] << ",average=" << aves[i] << endl;
	}
}