//算法生成0-9以内部重复的随机数

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
	//随机弹出数并存入v2
	for(int i=0;i<MAXSIZE;i++)
	{
		position = rand() % left;
		v2.push_back(v1[position]);
		v1.erase(v1.begin() + position);//清除这个元素，vector长度会减少
		left--;
	}
	//遍历输出
	for(vector<int>::iterator iter=v2.begin();iter!=v2.end();iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}