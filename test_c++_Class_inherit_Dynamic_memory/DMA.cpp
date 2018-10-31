#define _CRT_SECURE_NO_WARNINGS
#include"DMA.h"
#include<cstring>

//基类实现
baseDMA::baseDMA(const char* l, int r)//默认构造
{
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA& rs)//拷贝构造
{
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	//baseDMA(rs);//调用拷贝构造，为什么这里调用构造函数不行？明明代码一样，待解决
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

ostream& operator<<(ostream& os, const baseDMA& rs)
{
	//注意是字符串输出，直接cout指针
	cout << "label:"<<rs.label;
	cout << "rating:" << rs.rating;
	return os;
}

//派生类lacksDMA的实现

lacksDMA::lacksDMA(const char * c, const char * l, int r):baseDMA::baseDMA(l,r)//必须采用初始化列表的方式使得构造派生类成员和构造基类成员在同一起跑线上
{
	strncpy(color, c, 39);//把c指针指向的字符串前39个拷贝到color中，并返回color（第40个为'\0',所以不能拷）
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs):baseDMA::baseDMA(rs)
{
	strncpy(color, c, COL_LEN-1);//把c指针指向的字符串前39个拷贝到color中，并返回color（第40个为'\0',所以不能拷）
	color[COL_LEN-1] = '\0';
}

ostream& operator<<(ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;//重要：强转基类引用，调用基类重载<<，const baseMDA& temp=ls;接住也可以但是会多=重载构造
	os << "color:" << ls.color;
	return os;
}

//派生类hasDMA的实现

hasDMA::hasDMA(const char * s, const char * l, int r):baseDMA(l,r)//派生类默认构造函数
{
	style = new char[strlen(s) + 1];//字符串先开辟内存
	strcpy(style, s);//再拷贝内存
}

hasDMA::hasDMA(const char * s, const baseDMA & rs):baseDMA(rs)//派生类基类拷贝构造函数
{
	style = new char[strlen(s) + 1];//字符串先开辟内存
	strcpy(style, s);//再拷贝内存
}

hasDMA::hasDMA(const hasDMA & hs):baseDMA(hs)//派生类拷贝构造函数，先构造基类部分，因为const baseDMA& temp能接住hs进行hs基类部分的构造
{
	//对新的派生成员部分进行拷贝构造
	style = new char[strlen(hs.style) + 1];//字符串先开辟内存
	strcpy(style, hs.style);//再拷贝内存
}

hasDMA::~hasDMA()
{
	delete[] style;//析构调派生类部分后会自动调用基类部分
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;//1.先考虑自等
	//2.析构内存(释放基类和派生类的内存)
	baseDMA::operator=(hs);//1.因为const baseDMA& temp能接住hs 但也只能进行基类部分的=2.operator=的过程中包含了对基类的内存释放
	delete[] style;
	style = new char[strlen(hs.style) + 1];//字符串先开辟内存
	strcpy(style, hs.style);//再拷贝内存
	return *this;
}

ostream & operator<<(ostream & os, const hasDMA & hs)
{
	os << (const baseDMA&)hs;//强转+调用基类引用，向上的强转是合法的？待解决，原理是什么
	os << "style:" << hs.style;
	return os;

	// TODO: 在此处插入 return 语句
}