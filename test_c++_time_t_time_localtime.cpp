#include <iostream>
/*����timeͷ�ļ�*/
#include <time.h>
using namespace std;
int main()
{
	//time_t��long���ͣ���ȷ���룬�ǵ�ǰʱ���1970��1��1�����ʱ��Ĳ�
	const time_t t = time(NULL);
	cout << "current time is " << t << endl;
	/*����ʱ�䣺���ڣ�ʱ�� �����գ����ڣ�ʱ����*/
	struct tm* current_time = localtime(&t);
	printf("current year is %d;current month is %d;current date of month is %d\r\n",
		1900 + current_time->tm_year,
		1 + current_time->tm_mon/*��month�ķ�ΧΪ0-11*/,
		current_time->tm_mday);
	printf("current day of year is %d;current day in week is %d\r\n",
		current_time->tm_yday,/*��ǰ�����ǽ���ĵڶ�����[0,365] */
		current_time->tm_wday/*days since Sunday - [0,6] */);
	printf("time part %d:%d:%d \r\n",
		current_time->tm_hour,
		current_time->tm_min,
		current_time->tm_sec);
	printf("\t����ʱ�䣺%d-%d-%d %d:%d:%d\r\n",
		current_time->tm_year + 1900,
		current_time->tm_mon + 1,
		current_time->tm_mday,
		current_time->tm_hour,
		current_time->tm_min,
		current_time->tm_sec);
	/*��������ʱ��*/
	struct tm* current_gmtime = gmtime(&t);
	printf("��������ʱ�䣺%d-%d-%d %d:%d:%d\r\n",
		current_gmtime->tm_year + 1900,
		current_gmtime->tm_mon + 1,
		current_gmtime->tm_mday,
		current_gmtime->tm_hour,
		current_gmtime->tm_min,
		current_gmtime->tm_sec);
	//time/localtime���÷�-------
	time_t now;
	time(&now);// ��ͬ��now = time(NULL)
	printf("now time is %d\n", now);//����1970��1��1��0ʱ0��0�뵽��ʱ������
	//localtime
	time_t now;
	struct tm *tm_now;
	time(&now);
	tm_now = localtime(&now);
	printf("now datetime: %d-%d-%d %d:%d:%d\n",
		tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
	//------------
	system("pause");
	return 0;
}