#include<stdio.h>
#include<stdlib.h>
int* fun(int** walk);//利用int** 二级指针修改一级指针的指向
int add(int x, int y);
int minus(int x, int y);
typedef int(*fun_name)(int, int);
int c_math(int x, int y, fun_name fun_name);
int main()
{
	int* p = NULL;
	p = fun(&p);
	*p = 123;

	int*(*ptr)(int**) = fun;//定义一个函数指针
	(*ptr)(&p);//类似于指向数组的指针int* p=arr; p[2]..
			//利用函数指针和typedef实现对多个函数的调用
	
	int(*pp)(int, int) = add;
	printf("%d\n",(*pp)(1, 999));
	
	printf("%d\n", c_math(10, 9, minus));
	printf("%d\n", c_math(10, 9, add));
	//函数指针：在回调函数中使用较多
	//在做封装的时候使用较多
	//在做动态库的时候使用非常多

	//x：2 位域表示使用x的两位，比如100只取00，所以x：2为0
	//struct的大小，对齐和补齐,以空间换时间
	struct test
	{
		char name1;
		//
		//
		//
		int a;
		char name2;
		char name3;
		//
		//
	};
	printf("%d\n", sizeof(struct test));
}

int* fun(int** walk)
{
	*walk = (int*)malloc(sizeof(int));
	return *walk;
}

int add(int x, int y)
{
	return x + y;
}

int minus(int x, int y)
{
	return x - y;
}

int c_math(int x, int y, fun_name fun_name)
{
	return fun_name(x, y);
}
