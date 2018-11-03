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
	//就是想加这一句
	//baseDMA::baseDMA(rs);
	//调用拷贝构造，为什么这里调用构造函数不行？明明代码一样，待解决。已解决，因为调用了析构函数
	//三个问题：
	//1.在上面这句结束后会调用baseDMA::~baseDMA()的析构函数，造成提前释放，为什么会调用析构函数？
	//baseDMA::~baseDMA()并不是this对象来调用拷贝构造，这里会产生另一个哦
	//这里建议不要复写拷贝构造函数，构造函数，只有创建的时候会调用，baseDMA::~baseDMA()你这要写，它会任务你创建另一个对象，而不是this这个对象、
	//第一个明白了，相对于会创建一个临时对象，不是*this对象，所以在该临时对象脱离作用域后会调用析构函数
	//2.(能不能使用构造函数先放一放)明明是在baseDMA::作用域里面？为什么baseDMA::不写不行？
	//拷贝构造是怎么调用的：就是对象(对象)，对象=对象或者对象传参时候调用的，那就步可以这样调用啊，你确定，哦，那我以后显式调用拷贝构造都加作用域限定符好了
	//3.对于上面这种继承情况，到底该不该代码复用？（有风险吗）不建议代码复用要小心仔细处理，
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
