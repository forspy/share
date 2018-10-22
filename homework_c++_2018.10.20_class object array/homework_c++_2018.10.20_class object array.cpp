#include"class object array.h"
#include<iostream>
void pintArr(std::string(&tempArr)[3]);
using namespace std;
int main()
{
	using namespace std;
	student stu[4];
	string stu_ID[4];
	double stu_score[4];
	insert(&(stu[0]), &(stu_ID[0]), stu_score, 4);
	score_max(&(stu[0]), 4);
	

	//测试
	int a[3] = { 1,2,3 };
	cout << &a << endl;
	int(*p)[3] = &a;
	cout << p[2] << endl;
	//-----
	std::string arr[3] = {"凯文","广广","danny"};
	pintArr(arr);
}

void pintArr(std::string (& tempArr)[3])
{
	cout << tempArr[2] << endl;
	cout << *(tempArr + 2) << endl;
}

/*
我写的引用整个对象数组的方式，写了一个指向整个一般数组的数组指针，这里有两个问题
1：为什么引用整个对象数组std::string (& tempArr)[3]通过下标[2]能得到正确的值，而数组指针int(*p)[3]通过下标[2]只能得到地址？
2.按照我的理解指向整个数组的指针+1就会越界，为什么std::string (& tempArr)[3]这个引用了整个对象数组通过下标[0],[1],[2]能访问到正确的对象？
*/
/*
总结：一般来说数组不能引用，不过也可以引用整个数组，有点偏
数组会用向量vector去代替，传向量的引用就行了，现在可以先留下这个问题。先记住数组不能有引用，待解决
*/

