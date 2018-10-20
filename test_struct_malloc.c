#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//strcpy的头文件
#include<stdlib.h>//malloc free 的头文件
struct student//定义为全局变量的结构体方便给其他函数使用，全局变量存放在静态存储区
{
	char name[20];
	int age;
};
void print_student1(struct student a);
void print_student2(struct student* b);
int main()
{
	//int j=1;
	//int j=2;//重定义
	 int r,c;
    printf("row column\n");
    scanf("%d %d",&r,&c);
 
    int ** a;
    a=(int**)malloc(r*sizeof(int*));
 
    for(int i=0;i<r;i++){
        a[i]=(int*)malloc(c*sizeof(int));
    }
 
    printf("input\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("(%d,%d)",i,j);
            scanf("%d",&a[i][j]);
        }
    }
 
    printf("output\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
	//二维动态数组int a[3][3]; int** p=a; p[0]表示指向第一排 p[0][0]表示指向第一排的第一个
	
	//举个例子
	char kk[20];//kk是一个地址常量，不能直接kk="hello"
	char* p;
	p = "hello";
	printf("%s\n", p);
	strcpy(kk, "hello");
	printf("%s\n", kk);
	/////
	struct student xiaoming;
	strcpy(xiaoming.name ,"xiaoming");
	xiaoming.age = 18;
	printf("%s\n", xiaoming.name);

	struct student* ptr = (struct student*)malloc(sizeof(struct student));
	memset(ptr, 0, sizeof(struct student));//建议写，这样将动态变量初始化为0，如果是数组的话要*数组元素的个数
	strcpy(ptr->name, "xiaowang");
	ptr->age = 20;
	printf("%s\n%d\n", (ptr->name)+1, ptr->age);//这里ptr->name是一个指向name数组的指针，因为name本身是个数组，而ptr->age是一个变量
	free(ptr);

	//设置一个动态数组
	struct student* pp= (struct student*)malloc(10*sizeof(struct student));
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
	print_student1(xiaoming);
	print_student2(&xiaoming);//注意是地址传入
}
void print_student1(struct student a)//这样是把xiaoming的整个结构体再拷贝一遍
{
	printf("%s\n%d\n", a.name, a.age);
}

void print_student2(struct student* b)//这样是用一个结构体指针指向把xiaoming的整个结构体，节省了储存空间
{
	printf("%s\n%d\n", b->name, b->age);
}
