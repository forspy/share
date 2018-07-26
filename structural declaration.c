#include <stdio.h>
#include<stdlib.h>
#include<math.h>
struct point
{
	int x;
	int y;
};
struct point makepoint(int x, int y);
struct point pt = { 3,4 };
struct rect {
		struct point pt1;
		struct point pt2;
	};
struct rect screen = { 1,4, 5,6 };//≥ı ºªØ∏≥÷µ
int main() {
	printf("%d,%d\n", pt.x, pt.y);
	double dist;
	dist = sqrt((double)pt.x*pt.x + (double)pt.y*pt.y);
	printf("%f\n", dist);
	//screen.pt1.x = 3;
	printf("%d\n", screen.pt1.x);
	screen.pt1 = makepoint(30, 40);
	printf("%d %d\n", screen.pt1);
}

struct point makepoint(int x, int y) 
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}