#include<iostream>

int main()
{
	const int a = 1;
	const int* p = &a;
	//不能用int*类型的指针去指向const int类型的值，因为a是不能被修改的，而可以通过指针修改，所以产生了矛盾
	//同理
	const int months[12] = { 1,2,3 };
	const int* ptr = months;
	//这里months数组也是不能被修改的，所以不能用int* 类型的指针去指向

	int b = 1;
	int* const pointer = &b;
	//pointer = &a;int* const不允许修改指向
	*pointer = 2;//但允许利用指针修改b的值

}