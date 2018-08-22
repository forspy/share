#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//strcpy的头文件
#include<stdlib.h>//malloc free 的头文件
int main()
{
	//int j=1;
	//int j=2;
	int jjj;
	struct sduent
	{
		char name[20];
		int age;
	};
	
	//举个例子
	char kk[20];//kk是一个地址常量，不能直接kk="hello"
	char* p;
	p = "hello";
	printf("%s\n", p);
	strcpy(kk, "hello");
	printf("%s\n", kk);
	/////
	struct sduent xiaoming;
	strcpy(xiaoming.name ,"xiaoming");
	xiaoming.age = 18;
	printf("%s\n", xiaoming.name);

	struct sduent* ptr = (struct sduent*)malloc(sizeof(struct sduent));
	memset(ptr, 0, sizeof(struct sduent));//建议写，这样将动态变量初始化为0，如果是数组的话要*数组元素的个数
	strcpy(ptr->name, "xiaowang");
	ptr->age = 20;
	printf("%s\n%d\n", (ptr->name)+1, ptr->age);//这里ptr->name是一个指向name数组的指针，因为name本身是个数组，而ptr->age是一个变量
	free(ptr);

	//设置一个动态数组
	struct sduent* pp= (struct sduent*)malloc(10*sizeof(struct sduent));
	int i;
	for (i = 0; i < 10; i++)
		(pp + i)->age = i;
	//测试部分
    printf("i的值%d\n", i);//如果想保留i的值，需要这样定义（循环外面先定义i，然后里面不重定义直接赋值）
	//如果不想保留i的值
	/*
	1.里面重定义
	for (int i = 0; i < 10; i++)
	(pp + i)->age = i;
	2.外面赋值i=0里面仍然重定义int i

	总结：只要里面重定义了int i，这里的i就是个临时变量，在for循环结束后会被释放
	*/
	//
	while ( i < 3)
		i++;
	
	//测试部分
	//结论，for/while循环内的只要重新定义的变量比如i，j等会被释放掉，而使用外部的变量会被保留
	//如上例子，在循环外声明的i，在循环里面做的操作，包括初始化、赋值等，都会改变i的值；
	//循环体内部定义的比如j，在循环结束时就释放了，所以在后面还可以定义int j = 2，而不会报错
	for (int i = 0; i < 10; i++)
		printf("%d\n", (pp + i)->age);
	free(pp);
}