//c++��һ����Ҫ��Ŀ���Ǵٽ��������ã����м̳���ʵ��������Ŀ��֮һ
//has-a�Ĺ�ϵҲ����ʵ�ִ������ã�������������ʹ�����Ա��˽�м̳С������̳�
//��ģ��Ҳ����ʵ�ִ�������
//Ŀ�����һ��Student�࣬�����Ա���������������飬���ǿɱ䳤�ȵġ��������е����Ա����1.��������ʹ��string�����
//2.�������ʹ��ģ��������valarray
//����valarray��
/*
valarry����ͷ�ļ�<valarray>֧�ֵģ����ڴ���������ֵ������֧�ֽ�����������Ԫ�ص�ֵ��ӣ��Լ����������ҳ�������Сֵ�Ȳ���
*/
#include<valarray>
#include<string>
#include<iostream>
#include"Student.h"
using namespace std;
void set(Student& sa, int n);
const int pupils = 3;
const int quizzes = 5;
int main()
{
	valarray<double> v1;//����һ��double���͵�0��Ԫ�ص����飨valarrayҲ��Ҫ���ƿռ�std��֧�֣�
	valarray<int>v2(8);//8��Ԫ�ص�����
	valarray<int>v3(10,8);//8��Ԫ�ص�����,ÿ��Ԫ����Ϊ10
	double gpa[5] = { 1,2,3,4,5 };
	valarray<double>v4(gpa, 4);//4��Ԫ�����飬4��ֵΪgpa�����ڵ�ֵ
	valarray<int>v5 = { 1,2,3,4,5 };//Ҳ����ʹ�������ʼ��
	/*
	������������һЩ������
	[]����Ԫ�أ�����operator[]��
	size()���ذ�����Ԫ��
	sum()����Ԫ�ص��ܺ�
	max()�������ֵ��Ԫ��
	min()������Сֵ��Ԫ��
	*/
	cout << v5.max() << v5.min() << endl;
	Student ada[pupils] = { Student(quizzes),Student(quizzes),Student(quizzes) };
	int i;
	for (i = 0; i < pupils; ++i)
		set(ada[i], quizzes);//����
	cout << "Student list" << endl;
	for (i = 0; i < pupils; ++i)
		cout << ada[i].Name() << endl;//�������
	for (i = 0; i < pupils; ++i)
	{
		cout << ada[i];
		cout << "average:" << ada[i].Average() << endl;
	}
}
void set(Student& sa, int n)
{
	cout << "������ѧ��������";
	getline(cin, sa);
	cout << "Please enter" << n << "quiz scores" << endl;
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')//��������ַ�
		continue;
}
