#pragma once
#include<string>

class student
{
private:
	std::string ID;//ѧ�ţ�string����������ID�����Զ������ڴ棩
	double score;//�ɼ�
public:
	student();//Ĭ�Ϲ��캯��
	student(const std::string s_ID,const double s_score);//���ι��캯��
	std::string return_ID() { return ID; }
	double return_score() { return score; }
};//class����Ҫ��{ };�ֺ�

void score_max(student* ptr,int n);
void insert(student* stu, std::string* stu_ID, double* stu_score, int n);