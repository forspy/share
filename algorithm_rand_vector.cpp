//�㷨����0-9���ڲ��ظ��������

#include<iostream>
#include<ctime>
#include<list>
#include<vector>
#define MAXSIZE 10
using namespace std;

int main(int argc,char** argv)
{
	vector<int> v1,v2;
	int position;
	int left = MAXSIZE;
	for(int i=0;i<MAXSIZE;i++)
	{
		v1.push_back(i);
	}
	srand((unsigned)time(NULL));
	//���������������v2
	for(int i=0;i<MAXSIZE;i++)
	{
		position = rand() % left;
		v2.push_back(v1[position]);
		v1.erase(v1.begin() + position);//������Ԫ�أ�vector���Ȼ����
		left--;
	}
	//�������
	for(vector<int>::iterator iter=v2.begin();iter!=v2.end();iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}