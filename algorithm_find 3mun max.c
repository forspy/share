#include <stdio.h>

int main()
{
	int x, y, z ;
	x = 9;
	y = 10;
	z = 6;
	printf("%d\n", (y > z) ? (y > x ? y : x) : (z > x ? z : x));

}