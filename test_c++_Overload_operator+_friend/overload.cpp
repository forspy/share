#include<iostream>
#include"overload.h"

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)//Ĭ�ϲ�������ʼ��
{
	hours = h;
	minutes = m;
}
void Time::addmin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::addhour(int h)
{
	hours += h;
}
void Time::reset(int h, int m)
{
	hours = h;
	minutes = m;
}
//����һ��Time����
Time Time::sum(const Time& t)const//ע����������ã�����������ȴֻ��һ�����󣬽���������Ϊ���õ�Ŀ����Ϊ�����Ч�ʣ������ֵ����Time���󣬴���Ĺ��ܽ���ͬ
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

void Time::show()const
{
	std::cout << hours << "hours," << minutes << "minutes" << std::endl;
}

Time Time::operator+(const Time& t)const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time Time::operator-(const Time& t)const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = this->minutes + 60 * (this->hours);
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}
Time Time::operator*(double mult)const
{
	Time result;
	long totalminutes = (long)(hours*mult * 60 + minutes*mult);
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time operator*(double mult, const Time& t)//��Ԫ�����Ĵ�����Ҫ��Ϊ��������Ķ����ܹ����ʵ����е�˽�г�Ա
{
	Time result;
	long totalminutes = (long)(t.hours*mult * 60 + t.minutes*mult);
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

void tt(int h)
{
	Time temp;
	temp.addhour(h);//һ�㺯��Ҳ���Խ��������������Ա����
}