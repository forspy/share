#pragma once
#include<iostream>
#include<string>
using namespace std;
class String
{
private:
	static int num;//��̬��Ա
	int len;
	string* str;//��Ϊ��Ҫ�ڶ��Ͽ��ڴ棬������Ҫһ��string*��ָ��
public:
	String();//Ĭ�Ϲ��캯��
	String(const string& st);//Ĭ�ϴ��ι��캯��
	String(const String& origin);//�������캯��
	String& operator=(const String& st);//����=��ȸ���
	~String();
	String operator+(const String& b)const;
	friend ostream& operator<<(ostream& os, const String& st);//��Ϊostream���ⲿ�࣬Ϊ����os�ܹ����ʵ�String���ڲ��ĳ�Ա����Ҫ������Ԫ����

};
void call(const String temp);