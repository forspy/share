#include<iostream>
#include<cmath>
using namespace std;
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
const double Pi = 3.1415926;
void rect_to_polar(struct rect* rect1, struct polar* polar1);
int main()
{
	struct rect rect1;
	struct polar polar1;
	cout << "enter x y" << endl;
	if (cin >> rect1.x >> rect1.y)//cin正确输入将返回ture，否则返回false
	{
		rect_to_polar(&rect1, &polar1);//要通过指针改动polar1的值就要传递polar1的地址
		cout << "r=" << polar1.r << " angle=" << polar1.angle << endl;
	}
	else
	{
		cout << "enter error" << endl;
		cin.clear();//注意清除缓存
	}
}

void rect_to_polar(struct rect* rect1, struct polar* polar1)
{
	polar1->r = sqrt(rect1->x*rect1->x + rect1->y*rect1->y);
	polar1->angle = atan2(rect1->y, rect1->x)*180/Pi;
}