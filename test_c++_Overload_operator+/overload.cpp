#include<iostream>
#include"overload.h"

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)//默认参数化初始化
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
//返回一个Time对象
Time Time::sum(const Time& t)const//注意参数是引用，但返回类型却只是一个对象，将参数声明为引用的目的是为了提高效率，如果按值传递Time对象，代码的功能将相同
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