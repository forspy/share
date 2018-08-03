#include<stdio.h>
#include<stdlib.h>


//int *p;
main()
{
	int m;
	int *p=&m;
	printf("p指向的m的地址%d\n", p);
	printf("p指针变量里存放的值%d\n", *(p -3));

}
