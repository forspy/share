#include<stdio.h>
//矩形坐标规范化
#define min(a,b) ((a<b)?a:b);
#define max(a,b) ((a>b)?a:b);
struct point 
{
	int x;
	int y;
};

struct rect
{
	struct point pt1;
	struct point pt2;
};
struct rect canonrect(struct rect r);
int ptinrect(struct point p, struct rect r);

struct point pointmake(int x, int y);

int main()
{
	int x, y;
	struct point pp;
	struct rect rectangle;
	
	printf("请输入坐标x，y\n");
	scanf("%d%d", &x, &y);
	pp = pointmake(x, y);
	rectangle.pt1 = pointmake(1, 1);
	rectangle.pt2 = pointmake(10, 10);
	if (ptinrect(pp, canonrect(rectangle)))//矩形坐标规范化
	{
       printf("点（%d,%d）在矩形内\n",x,y);
	}
	else
	{
		printf("点（%d, %d）不在矩形内！\n", x, y);
	}
}

struct point pointmake(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x &&p.x < r.pt2.x
		&& p.y >= r.pt1.y&&p.y < r.pt2.y;
}

struct rect canonrect(struct rect r)
{
	struct rect temp;
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}