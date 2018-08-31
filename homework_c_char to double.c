#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
int Decimal_size(char* arr,int size);
double char_to_double(char* p, int size, int float_position);
int main()
{
	char b[100];
	printf("请输入一个浮点字符串数字将以double类型输出\n");
	scanf("%s", &b);
	int size = strlen(b);
	int float_position=Decimal_size(b, size);
	int n = size - Decimal_size(b, size) - 1;//计算一共有几位小数
	//无附加0化输出
	char name[7] = "%.2lf";
	name[2] = n+'0';
	printf(name, char_to_double(b, size, float_position));
}
//找到.的位置
int Decimal_size(char* arr,int size)
{
	char* p = ".";
	for (int i = 0; i < size; i++)
	{
		if (strncmp(arr+i, p, 1)==0)
			return i;
	}
	return 0;
}
//将char值计算为double值
double char_to_double(char* p,int size,int float_position)
{
	double value=0;
	double temp = 0;
	for (int i = 0; i < size; i++)
	{
		if (i <= float_position)
		{
			temp = (p[i] - '0')*1.0 / pow(10, i - float_position+1);
			value = value + temp;
		}
		else
		{
			temp = (p[i] - '0')*1.0 / pow(10, i - float_position);
			value = value + temp;
		}
	}
	return value + 0.2;//需要加上'.'算入的值('.'-'0'为-2)
}