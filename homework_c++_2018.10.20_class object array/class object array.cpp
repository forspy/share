#include"class object array.h"
#include<iostream>
using namespace std;
student::student()
{
	this->ID = "\0";
	this->score = 0;
}
student::student(const std::string s_ID, const double s_score)
{
	this->ID = s_ID;
	this->score = s_score;
}

void score_max(student* ptr, int n)
{
	student temp;
	for (int i = 0; i < n; i++)
	{
		if (temp.return_score() < ptr->return_score())
			temp = *ptr;
		ptr++;
	}
	cout << "最高分学生：" << endl;
	cout << "学号为" << temp.return_ID() << endl;
	cout << "成绩为" << temp.return_score() << endl;
}

void insert(student* stu,string* stu_ID,double* stu_score, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的学号和成绩" << endl;
		cin >> stu_ID[i] >> stu_score[i];
		int flag = 1;//通过设置flag达到goto的效果
		while (flag)
		{
			flag = 0;
			for (int j = 0; j < i; j++)//检查输入学号是否相同
			{
				if (stu_ID[i] == stu_ID[j])
				{
					cout << "输入ID相同请重新输入" << endl;
					flag = 1;
					cout << "请输入第" << i + 1 << "个学生的学号和成绩" << endl;
					cin >> stu_ID[i] >> stu_score[i];
					break;
				}
			}
		}
		//student temp(stu_ID[i], stu_score[i]);
		*stu = student::student(stu_ID[i], stu_score[i]);
		stu++;
	}
}