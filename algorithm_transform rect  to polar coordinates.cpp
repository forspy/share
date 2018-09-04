#include <iostream>
#include<cmath>
using namespace std;
struct polar rect_to_polar(struct rect rect1);
const double Pi = 3.1415926;
struct rect
{
	double x;
	double y;
};
struct polar
{
	double r;
	double angle;
};
int main()
{
	struct rect rect1 = { 30,40 };
	struct polar polar1 = rect_to_polar(rect1);
	cout << "r=" << polar1.r << " angle=" << polar1.angle << endl;
}

struct polar rect_to_polar(struct rect rect1)
{
	struct polar polar1;
	polar1.r = sqrt(rect1.x*rect1.x + rect1.y*rect1.y);
	polar1.angle = atan2(rect1.y, rect1.x) * 180 / Pi;
	return polar1;
}