#include<stdio.h>
//核心，指针
int main()
{
	long a[] = { 1,2 };
	int* p = a;
	printf("数据类型long的大小为%d位\n", (int)(p + 1)*8 - (int)(p)*8);
}