#pragma once
#include<cstdlib>
#include<ctime>
class Customer
{
private:
	long arrive;//����һ������ʱ�� ����
	int processtime;//����һ�����˿͵�ATM��ǰ��Ҫ�����ʱ�� ����
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
	processtime = rand() % max_processing_time + 1;//ƽ������ʱ��1-3���ӣ����Ե�
}

