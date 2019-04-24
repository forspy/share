#include<stdio.h>
main()
{
	int a[5] = { 1,2,3,4,5 };
	int i;
	int count = 0;
	for (i = 0;i <= 3;i++)
		printf("%d", a[++count]);//循环内的其他变量先加，输出结果2345
}