#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include"class and dynamic memory.h"
using std::cout;
using std::endl;
int String_easy::num_strings = 0;//初始化
//拷贝构造（参数是类的对象）
String_easy::String_easy(const String_easy& other)//重要：如果类中有使用new的对象，在对这些对象进行复制时，需要对该类添加拷贝构造函数重新创建内存，进行深度复制
{
	/*
		不合适，对象和对象拷贝，this = 	other，那么this肯定是一个临时的对象，函数结束之前会释放内存。
		然后会造成你other对象的内存被释放掉哦
	*/
	
	this->len = other.len;//是不是这样一个一个拷贝过来就行了？是的，this.str需要分配内存,深拷贝，那只拷贝str指针呢，共享一块内存可不可以？
	this->str = new char[this->len + 1];//为了防止内存被释放掉堆临时对象新建了一块内存
	strcpy(str, other.str);
	num_strings++;   //这是什么东西,就是测试用的，说的是创建了多少个对象
	cout << num_strings << ":" << str << endl;
	//这样就是重新创建一个对象了，这样对吗？
	//this->str = new char;//这样行不行？
}

//利用动态数组构造函数
String_easy::String_easy(const char* s)
{
	len = strlen(s);//根据输入的字符大小决定长度
	this->str = new char[len + 1];//建立一个动态数组,字符串单独保存在堆内存中，对象仅保存了指向该内存堆的指针
	strcpy(str, s);//把s复制到str指向的内存中
	num_strings++;
	cout << num_strings << ":" << str << endl;
}

String_easy::String_easy()//默认构造函数
{
	len = 3;
	str = new char[len + 1];//
	strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ":" << str << endl;
}

//析构函数
String_easy::~String_easy()//使用析构函数可以确保对象过期时，对该对象使用的堆内存进行释放
{
	cout << str << "  deleted  ";
	num_strings--;
	cout << num_strings << "  left" << endl;
	delete[] str;//释放掉该对象创建的动态内存
}

std::ostream& operator<<(std::ostream& os, const String_easy& st)
{
	os << st.str;

	return os;
}
/*
这样做会产生二义性：
func(){a=0};
func(int n=0){a=n};
*/
//s1=s2满足
//s1=s1.operator=(s2) 返回的对象给s1
//也满足连等s0=s1=s2
//s0.operator=(s1.operator=(s2))
String_easy& String_easy::operator=(const String_easy& st)
{
	if (this == &st)//对st对象取地址如果等于this就说明
		return *this;//返回这个对象本身
	delete[] this->str;//释放掉左值对象开辟的老的堆内存
	this->len = st.len;
	this->str = new char[len + 1];//创建新的堆内存
	strcpy(this->str, st.str);//复制指向该堆内存的指针
	return *this;//返回这个对象
}