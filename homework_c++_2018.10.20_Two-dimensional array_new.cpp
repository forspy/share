#include<iostream>
using namespace std;

int main()
{
	int row, col;
	cout << "�����붯̬�����Сrow column" << endl;
	cin >> row >> col;
	int**p = new int* [row];//����һ��ָ������
	//Ϊÿ��ָ�뿪��һά��̬����
	for (int i = 0; i < row; i++)
	{
		p[i] = new int[col];
	}
	//ʹ�ö�ά��̬����
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p[i][j] = i*col + j;//��ֵ
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
	//�ͷ�
	//1.���ͷ�ָ��������һ��ָ���Ӧ��һά��̬�����ڴ�
	//2.���ͷ�һ��ָ������
	for (int i = 0; i < row; i++)
		delete[] p[i];
	delete[] p;
	//p = NULL;//���ɺ�ϰ��

	//�ڶ��ּ��׷���
	//0.����������ȱ����ֻ����������,����ָ���������ȷ���ģ�
	cout << "����row" << endl;
	cin >> row;
	//1.����һ������ָ��
	int(*ptr)[5] = new int[row][5];
	//����
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ptr[i][j] = 5 * i + j;
		}
	}
	//��ȡ
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
}