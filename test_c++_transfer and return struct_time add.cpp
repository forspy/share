#include<iostream>
using namespace std;
struct my_time
{
	int hours;
	int minutes;
};
const int Per_hour_to_minutes = 60;
struct my_time sum(struct my_time t1, struct my_time t2);
void show(struct my_time mytime);
int main()
{
	struct my_time day1 = { 5,45 };//�ṹ�����ʼ����ʽ
	struct my_time day2 = { 6,20 };

	struct my_time total = sum(day1, day2);
	show(total);
	struct my_time day3 = { 0,20 };
	show(sum(total, day3));
}

struct my_time sum(struct my_time t1, struct my_time t2)//ע�⺯������
{
	struct my_time total;
	total.hours = t1.hours + t2.hours + (t1.minutes + t2.minutes) / Per_hour_to_minutes;
	total.minutes= (t1.minutes + t2.minutes) % Per_hour_to_minutes;

	return total;//���ڲ���ؽṹ�壬c++���Է��ؽṹ��
}

void show(struct my_time mytime)
{
	cout << mytime.hours << "hours" << mytime.minutes << "minutes" << endl;
}