#include<cmath>
#include"vector.h"
using namespace std;

namespace VECTOR
{
	const double rad_to_deg = 45.0 / atan(1.0);//atan(1.0)是pi/4 角度转弧度
	void Vector::set_mag()
	{
		mag = sqrt(x*x + y*y);
	}
	void Vector::set_ang()
	{
		ang = atan2(y, x);//范围为[-pi,pi]
	}
	/*
	有两个点 point(x1,y1), 和 point(x2,y2);那么这两个点形成的斜率的角度计算方法分别是：
    float angle = atan( (y2-y1)/(x2-x1) );或float angle = atan2( y2-y1, x2-x1 );
 	atan 和 atan2 区别：1：参数的填写方式不同；2：atan2 的优点在于 如果 x2-x1等于0 依然可以计算，但是atan函数就会导致程序出错；
	*/
	void Vector::set_x()
	{
		x = mag*cos(ang);//cmath里面的三角函数参数都为弧度
	}
	void Vector::set_y()
	{
		y = mag*sin(ang);
	}

	//设定构造函数
	Vector::Vector()
	{
		x = y = mag = ang = 0;//初始为0
		mode = RECT;//默认模式为直角坐标
	}
	Vector::Vector(double n1, double n2, Mode form)//默认参数法设置初值
	{
		this->mode = form;
		switch (mode)
		{
		case VECTOR::Vector::RECT://VECTOR也可以不写
			x = n1;
			y = n2;
			set_mag();
			set_ang();
			break;
		case VECTOR::Vector::POL:
			mag = n1;
			ang = n2;
			set_x();
			set_y();
			break;
		default:
			cout << "坐标表示方式输入不正确" << endl;
			break;
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		this->mode = form;
		switch (mode)
		{
		case VECTOR::Vector::RECT://VECTOR也可以不写
			x = n1;
			y = n2;
			set_mag();
			set_ang();
			break;
		case VECTOR::Vector::POL:
			mag = n1;
			ang = n2;
			set_x();
			set_y();
			break;
		default:
			cout << "坐标表示方式输入不正确" << endl;
			break;
		}
	}

	Vector::~Vector()
	{
	}
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}
	Vector Vector::operator+(const Vector& b) const//返回一个Vector类型的对象 A+B
	{
		return Vector(x + b.x, y + b.y, RECT);//构造函数会自动生成一个对象A+B生成一个对象
	}
	/*
	以下实现与返回构造函数功能相同
	
	Vector Vector::operator+(const Vector& b)const
	{
		Vector sum;
		sum.x = x + b.x;
		sum.y = y + b.y;
		sum.set_ang();
		sum.set_mag();
		return sum;
	}
	*/
	Vector Vector::operator-(const Vector& b)const//A-B
	{
		return Vector(x - b.x, y - b.y, RECT);//使用构造函数生成一个对象并返回
	}
	Vector Vector::operator-()const//-A
	{
		return Vector(-x, -y);//使用构造函数生成一个对象并返回
	}
	Vector Vector::operator*(double n)const//A*2,定义对象的乘法
	{
		return Vector(n*x, n*y);//使用构造函数生成一个对象并返回
	}
	//友元函数
	Vector operator*(double n, const Vector& a)//2*A
	{
		return a*n;//由于已经定义了A*2，直接调用该方法返回一个对象即可
	}
	//友元函数
	//重载<< 准备以直角坐标或者极坐标形式输出
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)//这里operator<<()是一个友元函数，不在类作用域内，因此必须使用Vector::RECT
			os << "(x,y)=(" << v.x << "," << v.y << ")" << endl;
		else if (v.mode == Vector::POL)
			os << "(mag,ang)=(" << v.mag << "," << v.ang*rad_to_deg << ")" << endl;
		else
			os << "错误！" << endl;
		return os;//返回可以保存os对象
	}
}
