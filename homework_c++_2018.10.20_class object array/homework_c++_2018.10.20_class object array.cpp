#include"class object array.h"
#include<iostream>
void pintArr(std::string(&tempArr)[3]);
using namespace std;
int main()
{
	using namespace std;
	student stu[4];
	string stu_ID[4];
	double stu_score[4];
	insert(&(stu[0]), &(stu_ID[0]), stu_score, 4);
	score_max(&(stu[0]), 4);
	

	//����
	int a[3] = { 1,2,3 };
	cout << &a << endl;
	int(*p)[3] = &a;
	cout << p[2] << endl;
	//-----
	std::string arr[3] = {"����","���","danny"};
	pintArr(arr);
}

void pintArr(std::string (& tempArr)[3])
{
	cout << tempArr[2] << endl;
	cout << *(tempArr + 2) << endl;
}

/*
��д������������������ķ�ʽ��д��һ��ָ������һ�����������ָ�룬��������������
1��Ϊʲô����������������std::string (& tempArr)[3]ͨ���±�[2]�ܵõ���ȷ��ֵ��������ָ��int(*p)[3]ͨ���±�[2]ֻ�ܵõ���ַ��
2.�����ҵ����ָ�����������ָ��+1�ͻ�Խ�磬Ϊʲôstd::string (& tempArr)[3]���������������������ͨ���±�[0],[1],[2]�ܷ��ʵ���ȷ�Ķ���
*/
/*
�ܽ᣺һ����˵���鲻�����ã�����Ҳ���������������飬�е�ƫ
�����������vectorȥ���棬�����������þ����ˣ����ڿ���������������⡣�ȼ�ס���鲻�������ã������
*/

