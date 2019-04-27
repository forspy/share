#include <stdio.h>

char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},//不是闰年
	{0,31,29,31,30,31,30,31,31,30,31,30,31 }//瑞年
};
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
main()
{
	int day, month, year;
	int year1, day1;
	int pmonth,pday;
	printf("请输入年月日\n");
	scanf("%d%d%d", &year,&month,&day);
	day = day_of_year(year,month,day);
	printf("第%d年第%d天\n", year, day);
	printf("请输入何年的第几天\n");
	scanf("%d%d", &year1, &day1);
	month_day(year1,day1,&pmonth,&pday);//把pmonth的地址和pday的地址传进去
	printf("%d年%d月%d日\n",year,pmonth,pday);
	
}

int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);//逻辑表达式的值只有0或1 闰年：能被4整除不能被100整除或者能被400整除
	for (i = 1; i <month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;//要返回多个变量值用指针
}





