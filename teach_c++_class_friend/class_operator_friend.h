#pragma once
#include<iostream>
using namespace std;
class point2D
{
private:
	int x_2D;
	int y_2D;
public:
	point2D(int x = 0, int y = 0):x_2D(x),y_2D(y){}
	friend void print_2D(point2D& point);
	friend class point3D;//ʹ�ø�����point2D�ķ���Ȩ��
};



class point3D
{
private:
	point2D m_p;
	int m_z;
public:
	//point3D(point2D& point,int z = 0) :point2D(point),m_z(z){}//ֻ�ǵ��ù��캯�����ֲ����������m_p����Ĺ��������Իᱨ��
	point3D(int x = 0, int y = 0, int z = 0);
	void print_3D() { cout << m_p.x_2D << "," << m_p.y_2D << "," << m_z << endl; }
	
};