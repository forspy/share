#pragma once
#include<iostream>
#include<string>
#include<valarray>
using namespace std;
class Student//�Ƚϵ��͵�has-aģ�ͣ�Student���а�����string�����ֺ�valarray<>ģ�����һϵ�гɼ�����ʹ�������Ա�ķ���
{
private:
	string m_name;
	valarray<double> m_scores;
	ostream& arr_out(ostream& os);
public:
	Student():m_name("Nobody"),m_scores(){ }
	explicit Student(const string& s):m_name(s),m_scores(){ }
	explicit Student(int n):m_name("Nully"),m_scores(n){ }//��ֹ��ʽ���͵��Զ�ת�������²��ֳ�Աû�и�ֵ
	Student(const string& s,int n):m_name(s),m_scores(n){ }
	Student(const string& s,const valarray<double>& a):m_name(s),m_scores(a){ }//valarray�а���valarray��ʲô�������
	Student(const char* str,const double* pd,int n):m_name(str),m_scores(pd,n){ }//����double���͵�����pd ǰn��,
	//��ʼ��˳��Ϊ��Ա��������˳�򣬶����������ڳ�ʼ���б��е�˳�򣬵�һ����Ա����һ����Ա�ĳ�ʼ����һ���ֵ�ʱ��˳��ͱȽ���Ҫ��
	~Student(){ }
	double Average();//
	string& Name();
	double& operator[](int i);
	double operator[](int i)const;//Ϊ���������Լ�const�ں��棬��ʾ�����޸Ķ���
	//��Ԫ ��Ԫ�����Ĵ�����Ҫ��Ϊ��������Ķ����ܹ����ʵ����е�˽�г�Ա
	friend istream& operator >> (istream& is, Student& stu) ;//1 word �������friend��stu�����ܷ��ʵ�Student�����˽�г�Ա
	friend istream& getline(istream& is, Student& stu);//1 line
	friend ostream& operator<<(ostream& os,Student& stu);
	//���д�.�������sizeof�������أ�5���� ���Ա����(.)��ָ���Ա��ָ�� (.*)����Χ���� (::)���������ʽ (? :)����sizeof��
	//= () [] -> ->* �����ǳ�Ա����
	//<< >>��Ԫ����
	//��Ŀ�����Ա
	//˫Ŀ������Ԫ
};
