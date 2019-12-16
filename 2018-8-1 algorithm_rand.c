#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//利用系统时间time(NULL)+随机数种子srand()+随机数rand()实现随机数
//如果没有前面的几个将产生固定的数值;
//这样产生的随机数
main()
{
	double d = 0.0;
	srand((unsigned)time(NULL));

	//r = (double)(rand() / (RAND_MAX + 1.0));
	for (int i = 0; i < 12; i++)
	{
		//d = ((double)rand()) / RAND_MAX;
		printf("%d\n", rand() % 10);//这个可以产生0-9  rand()%10 表示除以10余几
									//printf("%f\n", d);//产生的效果一般0-1
	}
}