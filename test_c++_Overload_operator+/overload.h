#pragma once
class Time
{
private:
	int hours;
	int minutes;
public:
	Time();//���캯��
	Time(int h, int m = 0);
	void addmin(int m);
	void addhour(int h);
	void reset(int h = 0, int m = 0);
	Time sum(const Time& t)const;
	Time operator+(const Time& t)const;//ΪTime����Ӽӷ����㣨��Ҫ��
	Time operator-(const Time& t)const;
	void show()const;
};