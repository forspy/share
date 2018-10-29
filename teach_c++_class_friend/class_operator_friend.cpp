#include "class_operator_friend.h"

void print_2D(point2D & point)
{
	cout << point.x_2D << "," << point.y_2D << endl;
}

point3D::point3D(int x, int y, int z)
{
	m_p.x_2D = x;
	m_p.y_2D = y;
	m_z = z;
}
