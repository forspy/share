#include<iostream>
#include<time.h>

using namespace std;
int main()
{
	//cout << clock()<<endl;
	//cout << "需要延时几秒\n" << endl;
	clock_t sec;
	cin >> sec;
	clock_t delay = sec*CLOCKS_PER_SEC;//CLOCK_PER_SEC是计算机上的秒数单位
	cout << "开始" << endl;
	clock_t start = clock();
	while (clock() - start < delay)
		;
	cout << "结束" << endl;
	return 0;
}