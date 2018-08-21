#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//利用系统时间time(NULL)+随机数种子srand()+随机数rand()实现随机数
//如果没有前面的几个将产生固定的数值;
//这样产生的随机数就是0-99之间的
//这样产生的随机数
main()
{
	
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		double temp = (rand() % 11)/10.0;//(0-10随机数)/10.0=0-1的随机数
		printf("%lf\n", temp);
	}
	////r = (double)(rand() / (RAND_MAX + 1.0));
	//for (int i = 0; i<12; i++)
	//	//printf("%f\n", (double)rand());
	//	printf("%d\n", rand() % 100);//注意%
	//for (int i = 0; i < 12; i++)
	//{
	//	//d = ((double)rand()) / RAND_MAX;
	//	printf("%d\n", rand() % 10);//这个可以产生0-10
	//								//printf("%f\n", d);//产生的效果一般0-1
	//}
}