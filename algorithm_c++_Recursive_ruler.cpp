#include<iostream>
using namespace std;
const int Len= 66;//2��n�η�+2�԰�ֳ�������ÿ�
const int level = 6;

void set_mark(char* r, int low, int high, int level);
int main()
{
	char ruler[Len];//��һ��64�׵ĳ��ӣ���Ҫ��ruler[0]��ruler[65]������'|'��ruler[66]='\0'
	const int min = 0;
	const int max = Len - 2;
	for (int i = 0; i < Len; i++)
		ruler[i] = ' ';
	ruler[min] = '|';
	ruler[max] = '|';
	ruler[Len - 1] = '\0';
	//cout << ruler << endl;
	for (int i = 0; i <= level; i++)
	{
		set_mark(ruler, min, max, i);
		cout << ruler << endl;
		for (int j = 1; j < Len - 2; j++)
			ruler[j] = ' ';//reset ruler
	}
}

void set_mark(char* r, int low , int high, int level)
{
	
	if (level == 0)
		return;
	int mid = (low + high) / 2;
	r[mid] = '|';
	set_mark(r, low, mid, level - 1);
	set_mark(r, mid, high, level - 1);
}
/*
|                                                               |
|                               |                               |
|               |               |               |               |
|       |       |       |       |       |       |       |       |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/