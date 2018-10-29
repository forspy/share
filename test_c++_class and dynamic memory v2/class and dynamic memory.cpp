#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"class and dynamic memory.h"

int String_medium::num_strings = 0;//初始化
//拷贝构造（参数是类的对象）
String_medium::String_medium(const String_medium& other)//重要：如果类中有使用new的对象，在对这些对象进行复制时，需要对该类添加拷贝构造函数重新创建内存，进行深度复制
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
String_medium::String_medium(const char* s)
{
	len = strlen(s);//根据输入的字符大小决定长度
	this->str = new char[len + 1];//建立一个动态数组,字符串单独保存在堆内存中，对象仅保存了指向该内存堆的指针
	strcpy(str, s);//把s复制到str指向的内存中
	num_strings++;
	cout << num_strings << ":" << str << endl;
}

String_medium::String_medium()//默认构造函数
{
	len = 0;
	str = new char[len + 1];//这样即使初始化为0也可以使用delete[] 释放
	num_strings++;
	//str = nullptr;//表示str是一个空指针，c++11引入
	str[0] = '\0';//也可以写成str=0;str=NULL
	
}

//析构函数
String_medium::~String_medium()//使用析构函数可以确保对象过期时，对该对象使用的堆内存进行释放
	//当在main中test* p=new test[4];在堆上开辟内存在delete[] 时调用析构，或者在栈上开辟内存时test A；在作用域结束时自动调用
{
	cout << str << "  deleted  ";
	num_strings--;
	cout << num_strings << "  left" << endl;
	delete[] str;//释放掉该对象创建的动态内存
}

ostream& operator<<(ostream& os, const String_medium& st)//不用写类作用域，本来友元函数也不在这个类里面
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
//考虑对象=对象
//也有默认的=重载，默认=重载是浅拷贝，会将当前对象的成员指针指向等号后面的对象，导致原堆丢失指向，内存泄漏，另外释放2个对象的时候会导致2次释放
String_medium& String_medium::operator=(const String_medium& st)
//为什么重载=要释放后开辟内存？因为对象已经开辟出来了而这个对象的大小可能和=对象不一样，所以要先delete，再开内存
{
	if (this == &st)//对st对象取地址如果等于this就说明
		return *this;//返回这个对象本身
	delete[] this->str;//释放掉左值对象开辟的老的堆内存
	this->len = st.len;
	this->str = new char[len + 1];//创建新的堆内存
	strcpy(this->str, st.str);//复制指向该堆内存的指针
	return *this;//返回这个对象
}
//考虑对象=char
String_medium& String_medium::operator=(const char* s)
{
	delete[] this->str;//先清掉当前对象的堆内存值
	this->len = strlen(s);
	this->str = new char[len + 1];
	strcpy(this->str, s);
	return *this;

}
/*
bool operator<(const String_medium& st1, const String_medium& st2)
{
if (strcmp(st1.str, st2.str) < 0)
return true;
else
return false;
}
*/
//进一步简写为
bool operator<(const String_medium& st1, const String_medium& st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String_medium& st1, const String_medium& st2)
{
	return (strcmp(st1.str, st2.str) > 0);
}
bool operator==(const String_medium& st1, const String_medium& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}
//比如"love"==answer将被转化为operator==("love",answer);进一步-->operator==(String_medium("love"),answer);?这里为什么"love"会自动转化为String_medium类型
//也就是说String_medium& st1能接住"love"，已解决利用String_medium构造函数接住"love"
//针对对象
char& String_medium::operator[](int i)
{
	return this->str[i];
}
//针对字符串"hello world"
const char& String_medium::operator[](int i)const
{
	return this->str[i];
}
//实现向类输入
istream& operator >> (istream& is, String_medium& st)
{
	char temp[String_medium::CLIMIT];
	is.get(temp, String_medium::CLIMIT);//这里其实已经完成了堆temp的输入，会保存在缓存里，如果在数组大小内或其他正确情况下
	//会把temp赋值给st，这样就给st插入值了
	if (is)
		st = temp;
	while (is&&is.get() != '\n')//这里用于清掉多余的缓存以及'\n'
		continue;
	return is;//返回is对象用于有时候判断输入情况
}
