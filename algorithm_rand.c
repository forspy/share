#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//利用系统时间time(NULL)+随机数种子srand()+随机数rand()实现随机数
//如果没有前面的几个将产生固定的数值;
//这样产生的随机数就是0-99之间的
main()
{
	double r;
	srand((unsigned)time(NULL));
	
	//r = (double)(rand() / (RAND_MAX + 1.0));
	for(int i=0;i<12;i++)
	//printf("%f\n", (double)rand());
	printf("%d\n", rand()%100);//注意%
}