#include <iostream>

int main()
{
	using namespace std;
	struct anti
	{
		int year;
	};

	anti s01, s02, s03;
	anti *p1 = &s01;//测试
	anti trio[3];//创建结构数组
	trio[0].year = 1990;//格式：数组（实体变量）.成员   重要
	(trio + 1)->year = 2000;//格式：指针(地址)->成员    超级重要 
	//或者(*(trio + 1)).year = 2000;解引用后变为实体才能用.
	//anti *arp = p1;
	anti* arp[3] = { &s01,&s02,&s03 };//创建一个结构指针数组
	//结构指针数组访问
	arp[0]->year = 1990;
	arp[1]->year = 2000;
	arp[2]->year = 2010;
	//注意arp是一个指针arp[2]才对应地址，需要对(*(arp[2])).year = 2010;    或者(**(arp + 2)).year = 2010;
	anti** ppa = arp;//因为arp是一个指针数组是anti**类型的需要两次解引用后才能变成实体，ppa的实质和arp是一样的
	cout << (*ppa)->year << endl << (*(ppa + 1))->year <<endl<< (*(ppa + 2))->year << endl;

}

