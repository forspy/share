#include<iostream>
int sum(int arr[][4], int size);
using namespace std;
int main()
{
	int data[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
	};
	int total = sum(data, 3);
	cout << total << endl;
}

int sum(int arr[][4], int size)//ע���ά����Ĵ��η�ʽ
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
			total = total + arr[i][j];
	}
	//ps:arr[i][j] = *(*(arr + i) + j);��Ӧ��ָ��ȡֵ
	return total;
}