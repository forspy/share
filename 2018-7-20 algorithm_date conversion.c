#include <stdio.h>

char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},//��������
	{0,31,29,31,30,31,30,31,31,30,31,30,31 }//����
};
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
main()
{
	int day, month, year;
	int year1, day1;
	int pmonth,pday;
	printf("������������\n");
	scanf("%d%d%d", &year,&month,&day);
	day = day_of_year(year,month,day);
	printf("��%d���%d��\n", year, day);
	printf("���������ĵڼ���\n");
	scanf("%d%d", &year1, &day1);
	month_day(year1,day1,&pmonth,&pday);//��pmonth�ĵ�ַ��pday�ĵ�ַ����ȥ
	printf("%d��%d��%d��\n",year,pmonth,pday);
	
}

int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);//�߼����ʽ��ֵֻ��0��1 ���꣺�ܱ�4�������ܱ�100���������ܱ�400����
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
	*pday = yearday;//Ҫ���ض������ֵ��ָ��
}





