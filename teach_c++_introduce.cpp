/*
QQ1-操作系统--底层硬件（tcp/ip）--底层硬件--操作系统--QQ2
分布式应用--ACE库
数字图像处理--openCV

计算机行业T型发展，先纵深再横向扩展T
endl清缓存
const char* p="hello";	
名称空间别名namespace abc=a:b:c
联合体内的变量共用一块内存
*/
#include<iostream>
typedef struct student
{
	char name[10];
	int age;
}STU;
struct s_student
{
	int m;
	void ss();
};
enum color
{
	RED,
	GREE
};
union MyUnion
{
	char i;
	int j;
};
int main()
{
	struct student s1;
	STU s2;
	s_student s3;
	//c++严格类型检查
	color a = RED;
	MyUnion U;
	std::cin >> U;
}