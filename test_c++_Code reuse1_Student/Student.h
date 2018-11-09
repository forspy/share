#pragma once
#include<iostream>
#include<string>
#include<valarray>
using namespace std;
class Student//比较典型的has-a模型，Student类中包含了string类名字和valarray<>模板类的一系列成绩，并使用了类成员的方法
{
private:
	string m_name;
	valarray<double> m_scores;
	ostream& arr_out(ostream& os);
public:
	Student():m_name("Nobody"),m_scores(){ }
	explicit Student(const string& s):m_name(s),m_scores(){ }
	explicit Student(int n):m_name("Nully"),m_scores(n){ }//防止隐式类型的自动转换而导致部分成员没有赋值
	Student(const string& s,int n):m_name(s),m_scores(n){ }
	Student(const string& s,const valarray<double>& a):m_name(s),m_scores(a){ }//valarray中包含valarray是什么？待解决
	Student(const char* str,const double* pd,int n):m_name(str),m_scores(pd,n){ }//储存double类型的数组pd 前n个,
	//初始化顺序为成员被声明的顺序，而不是他们在初始化列表中的顺序，当一个成员是另一个成员的初始化的一部分的时候，顺序就比较重要了
	~Student(){ }
	double Average();//
	string& Name();
	double& operator[](int i);
	double operator[](int i)const;//为了区分所以加const在后面，表示不能修改对象
	//友元 友元函数的存在主要是为了让里面的对象能够访问到类中的私有成员
	friend istream& operator >> (istream& is, Student& stu) ;//1 word 如果不加friend则stu对象不能访问到Student里面的私有成员
	friend istream& getline(istream& is, Student& stu);//1 line
	friend ostream& operator<<(ostream& os,Student& stu);
	//所有带.运算符和sizeof不能重载（5个） 类成员访问(.)，指向成员的指针 (.*)，范围解析 (::)，条件表达式 (? :)，和sizeof。
	//= () [] -> ->* 必须是成员函数
	//<< >>友元重载
	//单目建议成员
	//双目建议友元
};
