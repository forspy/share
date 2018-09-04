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
	if (cin >> rect1.x >> rect1.y)//cin��ȷ���뽫����ture�����򷵻�false
	{
		rect_to_polar(&rect1, &polar1);//Ҫͨ��ָ��Ķ�polar1��ֵ��Ҫ����polar1�ĵ�ַ
		cout << "r=" << polar1.r << " angle=" << polar1.angle << endl;
	}
	else
	{
		cout << "enter error" << endl;
		cin.clear();//ע���������
	}
}

void rect_to_polar(struct rect* rect1, struct polar* polar1)
{
	polar1->r = sqrt(rect1->x*rect1->x + rect1->y*rect1->y);
	polar1->angle = atan2(rect1->y, rect1->x)*180/Pi;
}