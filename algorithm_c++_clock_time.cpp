#include<iostream>
#include<time.h>

using namespace std;
int main()
{
	//cout << clock()<<endl;
	//cout << "��Ҫ��ʱ����\n" << endl;
	clock_t sec;
	cin >> sec;
	clock_t delay = sec*CLOCKS_PER_SEC;//CLOCK_PER_SEC�Ǽ�����ϵ�������λ
	cout << "��ʼ" << endl;
	clock_t start = clock();
	while (clock() - start < delay)
		;
	cout << "����" << endl;
	return 0;
}