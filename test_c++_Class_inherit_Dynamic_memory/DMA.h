#pragma once
#include<iostream>
using namespace std;
class baseDMA
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = "null", int r = 0);//默认构造
	baseDMA(const baseDMA& rs);//拷贝构造
	virtual ~baseDMA();//虚析构
	baseDMA& operator=(const baseDMA& rs);//=重载拷贝构造
	friend ostream& operator<<(ostream& os, const baseDMA& rs);//友元<<重载
};

class lacksDMA :public baseDMA//公有继承
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];//设置一个39个char类型的字符串
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);//默认构造
	lacksDMA(const char* c, const baseDMA& rs);//基类拷贝构造
	friend ostream& operator<<(ostream& os, const lacksDMA& rs);
	//不需要析构函数
};

class hasDMA :public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);//默认拷贝构造
	hasDMA(const char* s, const baseDMA& rs);//基类拷贝构造
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& hs);
	friend ostream& operator<<(ostream& os, const hasDMA& hs);
};