#include<iostream>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	using namespace std;
	int a = 6;
	int b = 5;
	int *c, *d;//每个都要申明*
	//在使用指针之前一定要初始化
	c = (int*)0x8000000;//c++要求在指针赋值时对常量进行强制类型的转换
	cout << &a << endl;
	cout << &b << endl;
	int *p = new int;//指针p是一个栈（stack）内存，p指向的内存是一个堆（heap）内存
	*p = 10086;
	cout << *p << endl;
	delete p;//1.释放new分配的内存2.但不会删除指针变量p 3.可以将p重新指向一个新的内存块4.不能将delete用于释放普通变量及指针
	int num=3;
	int *ptr = new int[num];//动态数组
	ptr[0] = 1;
	ptr[1] = 2;
	ptr[2] = 3;
	//cout << ptr << endl;
	//ptr[3] = 4;//不建议超出动态数组的界限，会导致内存溢出，释放不了
	//cout << ptr << endl;
	cout << ptr[2] << endl;//超出预想的数组后，new会自动创建2.拨动指针到第四个数组输出值等价于ptr[4]
	//ptr -= 2;
	delete []ptr;//释放内存注意加[]
	//动态数组的动态性体现在数组的大小可以先用变量指定,当在运行时指定完数组的大小之后其效果就和一般数组一样，使用完动态数组之后我们需要使用delete []释放
	//不然会有内存泄漏，指的是重复内存占用
	short tell[20] = { 1,2,3 };
	short(*pas)[20] = &tell;//指向20个元素的指针，指的是指向整个数组
	cout << (*pas)[1] << endl;//(*pas)与tell等价，注意括号
	short *p1 = &tell[0];
	short *p2 = &tell[2];
	cout << "指向同一数组的两个指针的间隔为" << p2 - p1 << endl;//
	//使用[]等价于对指针的解除引用
	//c语言中有一个relloc函数可以扩大已经定好的malloc函数的边界
	int *pp1 = (int*)malloc(100*sizeof(int));
	int *pp2 = (int*)realloc(pp1, 200 * sizeof(int));//使用realloc函数会释放上一个malloc函数的堆内存，所以不需要free（pp1），如果一开始什么都没有游客先传一个NULL
	//realloc相当于增加了100*sizeof(int)
	//free(pp1);
	free(pp2);
	//一个进程结束以后，它所使用的所有内存资源都会被OS回收
	//c语言memmove(ptr,ptr2,90) memcopy(ptr,ptr2,字节数)  内存拷贝其中ptr是目标地址，ptr2是要开始移动的地址，90是要移动的字节数
#if 0//条件编译
	ssss
#endif
	
}
