#include<stdio.h>
//主要是让代码变得优雅
//存在四个储存区：栈，堆，全局变量区，只读常量区
static int ab;//static修饰全局变量只能在这个.c文件里使用，减少代码的维护成本
void change(const int* p);
struct student
{
	char name[20];
	int age;
};
int main()
{
	const int a = 10;//const 修饰的变量不能被修改
	int xm;
	change(&xm);
	int* const ptr = &xm;
	//ptr = &xh;表示不能修改这个指针的指向
	static int abc;//将abc变为全局变量，但作用域只在函数内
	typedef unsigned int u_int;//typedef定义一个新的类型
	typedef struct student student;
	student xq;
	typedef struct student *student_ptr;//定义一个指针类型的struct student*，叫做student_ptr
	student_ptr xh = &xq;
	//FILE* 没有加struct就是typedef的作用，慎用
	//goto拨动指令指针，慎用跳出两层以上循环，打开多个文件，集中处理
	int j ;
again: j = 1;
	printf("%d\n", j);
	goto again;//使用以后让代码更优雅

}

void change(const int* p)
{
	//*p = 3;const修饰的指针表示该指针不能修改所指对象的值，但是可以修改p的指向
}
