#include<stdio.h>
#define swap(x,y,temp) temp=x;x=y;y=temp//加入临时变量交换
#define swap1(x,y) x=x^y;y=y^x;x=x^y//位运算交换
#define swap2(x,y) x=x-y;y=y+x;x=y-x//利用x，y之间的差值
int main()
{
	int temp;
	int x=1;
	int y=2;
	swap(x, y,temp);
	printf("x=%d y=%d\n", x, y);
	swap1(x, y);
	printf("x=%d y=%d\n", x, y);
	swap2(x, y);
	printf("x=%d y=%d\n", x, y);
}