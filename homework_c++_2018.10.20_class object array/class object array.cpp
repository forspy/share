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
	cout << "��߷�ѧ����" << endl;
	cout << "ѧ��Ϊ" << temp.return_ID() << endl;
	cout << "�ɼ�Ϊ" << temp.return_score() << endl;
}

void insert(student* stu,string* stu_ID,double* stu_score, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "��ѧ����ѧ�źͳɼ�" << endl;
		cin >> stu_ID[i] >> stu_score[i];
		int flag = 1;//ͨ������flag�ﵽgoto��Ч��
		while (flag)
		{
			flag = 0;
			for (int j = 0; j < i; j++)//�������ѧ���Ƿ���ͬ
			{
				if (stu_ID[i] == stu_ID[j])
				{
					cout << "����ID��ͬ����������" << endl;
					flag = 1;
					cout << "�������" << i + 1 << "��ѧ����ѧ�źͳɼ�" << endl;
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