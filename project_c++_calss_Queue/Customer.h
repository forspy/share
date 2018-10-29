#pragma once
#include<cstdlib>
#include<ctime>
class Customer
{
private:
	long arrive;//设置一个到达时间 分钟
	int processtime;//设置一个当顾客到ATM机前需要处理的时间 分钟
	int max_processing_time;
public:
	Customer() { arrive = 0; processtime = 0; }
	~Customer() {};
	void set(long when,int max_processing_time);
	long when()const { return arrive; }
	int ptime()const { return processtime; }
};
inline void Customer::set(long when,int max_processing_time)
{
	arrive = when;
	processtime = rand() % max_processing_time + 1;//平均处理时间1-3分钟，可以调
}

