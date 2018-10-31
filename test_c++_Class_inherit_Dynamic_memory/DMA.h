#pragma once
#include<iostream>
using namespace std;
class baseDMA
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = "null", int r = 0);//Ĭ�Ϲ���
	baseDMA(const baseDMA& rs);//��������
	virtual ~baseDMA();//������
	baseDMA& operator=(const baseDMA& rs);//=���ؿ�������
	friend ostream& operator<<(ostream& os, const baseDMA& rs);//��Ԫ<<����
};

class lacksDMA :public baseDMA//���м̳�
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];//����һ��39��char���͵��ַ���
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);//Ĭ�Ϲ���
	lacksDMA(const char* c, const baseDMA& rs);//���࿽������
	friend ostream& operator<<(ostream& os, const lacksDMA& rs);
	//����Ҫ��������
};

class hasDMA :public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);//Ĭ�Ͽ�������
	hasDMA(const char* s, const baseDMA& rs);//���࿽������
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& hs);
	friend ostream& operator<<(ostream& os, const hasDMA& hs);
};