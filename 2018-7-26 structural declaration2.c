#include <stdio.h>
struct point
{
	int x;
	int y;
};
struct point origin, *pp;
//struct point *pp = &origin;//这种声明初始化可以
//int a;
//int *p;//一般指针也不可以在全局变量里初始化
//p = &a;
struct point makepoint(int x, int y);
main()
{
    pp = &origin;//指针pp指向origin结构,结构化指针不能在全局变量里初始化
	origin = makepoint(3, 4);
	printf("1 origin is (%d,%d)\n", (*pp).x, (*pp).y);
	printf("2 origin is (%d,%d)\n", pp->x, pp->y);
}

struct point makepoint(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}