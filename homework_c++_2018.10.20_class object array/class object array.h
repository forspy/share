#pragma once
#include<string>

class student
{
private:
	std::string ID;//学号（string会根据输入的ID长度自动分配内存）
	double score;//成绩
public:
	student();//默认构造函数
	student(const std::string s_ID,const double s_score);//带参构造函数
	std::string return_ID() { return ID; }
	double return_score() { return score; }
};//class后面要有{ };分号

void score_max(student* ptr,int n);
void insert(student* stu, std::string* stu_ID, double* stu_score, int n);